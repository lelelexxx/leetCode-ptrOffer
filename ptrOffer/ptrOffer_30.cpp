//30:����min������ջ
//˫ջʵ�֣�һ��������һ������Сֵ����dataջ��pop���ľ�����Сֵʱ��minջ��ҲҪ����pop����Сֵ
class Solution {

	stack<int> s_data;
	stack<int> s_min;
public:
	void push(int value) {
		if (s_data.empty())
			s_min.push(value);
		s_data.push(value);
		if (value <= s_min.top())
			s_min.push(value);
	}
	void pop() {
		if (s_data.empty() || s_min.empty())
			return;
		if (s_data.top() == s_min.top())
		{
			s_data.pop();
			s_min.pop();
			return;
		}
		s_data.pop();

	}
	int top() {
		return s_data.top();
	}
	int min() {
		return s_min.top();
	}
};