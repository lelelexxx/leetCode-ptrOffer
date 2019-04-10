#include<condition_variable>//�������õ���������condition_variable��condition_variable_any��ǰ��ֻ�ܺ�mutexһ���������߿��Ժ�
							//�κ������׼�Ļ�����һ������һ����ѡǰ�ߣ�ʵ�ָ���Ч��

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
			std::unique_lock<std::mutex> lk(mux);//����ֻ��ʹ��unique_lock����Ϊunique_lock֧������Ȩ��ת�ƣ����Խ��в������ݡ�����lock_guard�ᱨ��
			data_cond.wait(lk, [] {return !data_queue.empty(); });//wait��ȡunique_lock�󣬸��ݺ����lambda���ʽ���������жϣ������������(queue��Ϊ��)�����wait()���أ�����������
																  //������������(queueΪ��)�������ô�������unique_lock���н��������ҽ����߳�������ֱ������������notify_one()�����ã����»���������
																  //�����Ѻ����»�ȡ�����������Ҷ������ٴμ�顣
			int data = data_queue.front();
			data_queue.pop();
			lk.unlock();//�����õ���unique_lock�����������ǰ�ֶ����������صȵ�unique_lock������
			process_data(data);

		}
	}
}


//�̰߳�ȫ�Ķ���
template<typename T>
class  threadsafe_queue
{
private:
	mutable std::mutex mut;//�ɱ�,Ϊ����const������Ҳ�ܽ��м���������empty()������
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
		data_cond.notify_one();//notiry_one����һ������wait���̡߳�
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

