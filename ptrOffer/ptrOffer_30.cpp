//30:包含min函数的栈
//双栈实现，一个存数，一个存最小值。当data栈中pop出的就是最小值时，min栈中也要跟着pop出最小值
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