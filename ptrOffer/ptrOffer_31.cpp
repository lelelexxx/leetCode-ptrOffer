//31,ջ��ѹ�뵯������

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		reverse(popV.begin(), popV.end());	//��pushV��popV��ת����ջ��ͨ��ֱ�ӱȽ�ջ���������ƺ�ʱpop��ʱpush��
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