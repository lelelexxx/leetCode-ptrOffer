#include<list>
#include<mutex>
#include<algorithm>
#include<vector>
#include<stack>
#include<exception>
#include<iostream>

struct empty_stack : std::exception
{
	const char* what() const throw()
	{
		return "empty stack!";
	}
};
template<typename T>
class threadsafe_stack
{
private:
	std::stack<T> data;
	mutable std::mutex m; //互斥量通常与被保护的数据放在同一个类中。
						  //mutable 只能用来修饰类的数据成员，使其可被const成员函数访问和修改。
public:
	threadsafe_stack()
		: data(std::stack<T>()) {}//默认构造

	threadsafe_stack(const threadsafe_stack& other) //拷贝构造
	{
		std::lock_guard<std::mutex> lock(other.m);//既然从别的地方拷贝数据过来，那当然要用别的互斥量来进行保护咯
		data = other.data;
	}

	threadsafe_stack& operator =(const threadsafe_stack&) = delete;//删除其赋值操作

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		data.push(new_value);
	}
	//这里用了两种方式进行pop
	//stl中，弹出栈顶元素用top+pop两步走战略。
	//若直接获取栈顶元素保存下来然后删除栈顶的话，若函数返回时存储空间不够了,抛出异常
	//那么栈顶的元素就丢失了。
	//采用先top再pop的策略，就能最大限度保证数据的安全。
	//如下的代码中采用传引用和返回智能指针的方式，也能有效避免上述问题。
	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(m);
		if (data.empty()) throw empty_stack();

		std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
		data.pop();
		return res;
	}

	void pop(T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		if (data.empty()) throw empty_stack();

		value = data.top();
		data.pop();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}

};

void stackTest(threadsafe_stack<int> stack, volatile int& count)
{
	
	while (!stack.empty())
	{
		std::shared_ptr<int> res = stack.pop();
		std::cout << *res << std::endl;
		count += 1;
	}
	std::cout << "safeTest end " << std::endl;
}
//
//void stackTest(std::stack<int> stack, int& count)
//{
//	for (int i = 0; i < 15; i++)
//	{
//		stack.push(i);
//	}
//	while (!stack.empty())
//	{
//		int res = stack.top();
//		stack.pop();
//		std::cout << res<< std::endl;
//
//	}
//	std::cout << "Test end " << std::endl;
//}
int main()
{
	threadsafe_stack<int> safe_stack;
	std::stack<int> stack;

	for (int i = 0; i < 100; i++)
	{
		safe_stack.push(i);
	}
	volatile int count1 = 0;//使得每次获取count的值的时候，都要往内存区取。
	volatile int count2 = 0;
	std::thread t1(stackTest, safe_stack, std::ref(count1));
	std::thread t2(stackTest, safe_stack, std::ref(count1));

	//std::thread ut1(stackTest, stack, std::ref(count2));
	//std::thread ut2(stackTest, stack, std::ref(count2));
	
	t1.join();
	t2.join();

	//ut1.join();
	//ut2.join();

	std::cout << "safeStack : " << count1 << std::endl;
	std::cout << "std::Stack : " << count2 << std::endl;
}