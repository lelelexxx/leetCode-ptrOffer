//31,栈的压入弹出序列

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		reverse(popV.begin(), popV.end());	//将pushV和popV翻转后入栈，通过直接比较栈顶，来控制何时pop何时push。
		reverse(pushV.begin(), pushV.end());

		stack<int, vector<int>> popS(popV);
		stack<int, vector<int>> pushS(pushV);

		stack<int> temp;
		while (!pushS.empty())
		{
			temp.push(pushS.top());
			pushS.pop();

			while (temp.top() == popS.top())
			{
				temp.pop();
				popS.pop();
				if (temp.empty() || popS.empty())
					break;
			}
		}
		return temp.empty();

	}
};