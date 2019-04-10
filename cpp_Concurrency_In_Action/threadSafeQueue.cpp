#include<condition_variable>//包含常用的条件变量condition_variable和condition_variable_any，前者只能和mutex一起工作，后者可以和
							//任何满足标准的互斥量一起工作。一般首选前者（实现更高效）

#include<thread>
#include<mutex>
#include<queue>
#include<memory>

void consumerAndproducer()
{
	std::mutex mux;
	std::queue<int> data_queue;
	std::condition_variable data_cond;
	long const buff_Size = 100;
	int prepare_data()
	{

	}
	void process_data(int data)
	{
	}
	void data_preparation_thread()
	{
		while (data_queue.size() < buff_Size)
		{
			int const data = prepare_data();
			std::lock_guard<std::mutex> lk(mux);
			data_queue.push(data);
			data_cond.notify_one();
		}
	}

	void data_processiong_thread()
	{
		while (true)
		{
			std::unique_lock<std::mutex> lk(mux);//这里只能使用unique_lock，因为unique_lock支持所有权的转移，可以进行参数传递。换成lock_guard会报错。
			data_cond.wait(lk, [] {return !data_queue.empty(); });//wait获取unique_lock后，根据后面的lambda表达式进行条件判断，如果条件满足(queue不为空)，则从wait()返回，并持有锁。
																  //若条件不满足(queue为空)，则利用传进来的unique_lock进行解锁，并且将该线程阻塞，直到条件变量的notify_one()被调用，重新唤醒消费者
																  //被唤醒后，重新获取互斥锁，并且对条件再次检查。
			int data = data_queue.front();
			data_queue.pop();
			lk.unlock();//由于用的是unique_lock，这里可以提前手动解锁，不必等到unique_lock析构。
			process_data(data);

		}
	}
}


//线程安全的队列
template<typename T>
class  threadsafe_queue
{
private:
	mutable std::mutex mut;//可变,为了在const函数中也能进行加锁解锁。empty()函数中
	std::queue<T> data_queue;
	std::condition_variable data_cond;
public:
	threadsafe_queue() {}
	threadsafe_queue(const threadsafe_queue& other)
	{
		std::lock_guard<std::mutex> lk(other.m);
		data_queue = other.data_queue;
	}
	threadsafe_queue& operator=(const threadsafe_queue&) = delete;

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(new_value);
		data_cond.notify_one();//notiry_one触发一个正在wait的线程。
	}
	bool try_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return false;
		value = data_queue.front();
		data_queue.pop();
		return true;
		
	}
	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
		data_queue.pop();
		return res;
	}

	void wait_and_pop(T& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_cond.wait(lk, [] {return !data_queue.empty(); });
		value = data_queue.front();
		data_queue.pop();
	}
	std::shared_ptr<T> wait_and_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		data_cond.wait(lk, [] {return !data_queue.empty(); });
		std::shared_ptr<T> data(std::make_shared<T>(data_queue.front()));
		data_queue.pop();
		return data;
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
};

