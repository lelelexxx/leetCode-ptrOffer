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
	mutable std::mutex m; //������ͨ���뱻���������ݷ���ͬһ�����С�
						  //mutable ֻ����������������ݳ�Ա��ʹ��ɱ�const��Ա�������ʺ��޸ġ�
public:
	threadsafe_stack()
		: data(std::stack<T>()) {}//Ĭ�Ϲ���

	threadsafe_stack(const threadsafe_stack& other) //��������
	{
		std::lock_guard<std::mutex> lock(other.m);//��Ȼ�ӱ�ĵط��������ݹ������ǵ�ȻҪ�ñ�Ļ����������б�����
		data = other.data;
	}

	threadsafe_stack& operator =(const threadsafe_stack&) = delete;//ɾ���丳ֵ����

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		data.push(new_value);
	}
	//�����������ַ�ʽ����pop
	//stl�У�����ջ��Ԫ����top+pop������ս�ԡ�
	//��ֱ�ӻ�ȡջ��Ԫ�ر�������Ȼ��ɾ��ջ���Ļ�������������ʱ�洢�ռ䲻����,�׳��쳣
	//��ôջ����Ԫ�ؾͶ�ʧ�ˡ�
	//������top��pop�Ĳ��ԣ���������޶ȱ�֤���ݵİ�ȫ��
	//���µĴ����в��ô����úͷ�������ָ��ķ�ʽ��Ҳ����Ч�����������⡣
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
	volatile int count1 = 0;//ʹ��ÿ�λ�ȡcount��ֵ��ʱ�򣬶�Ҫ���ڴ���ȡ��
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