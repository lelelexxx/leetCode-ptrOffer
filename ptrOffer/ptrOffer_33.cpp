

/*33�⣺�����������ĺ����������
		�ж�����[1,2,3,4,5]�Ƿ�Ϊ�����������ĺ���������С�
		Ҫ�ر�ע��ѭ������ʱ��ָ��λ�á�
		���⣬���ⷨ��Ϊ����[]ʱ��Ӧ����True��Ҫ����False�������������������һ�㺯����
*/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {

		vector<int> left, right;
		int temp = sequence.size() - 1;
		if (sequence.size() <= 2)
			return true;
		for (int i = 0; i < sequence.size() - 1; i++)
		{
			if (sequence[i] < sequence.back())
			{
				continue;
			}
			temp = i;
			break;
		}
		left = vector<int>(sequence.begin(), sequence.begin() + temp);
		for (auto i = temp; i < sequence.size() - 1; i++)
		{
			if (sequence[i] < sequence.back())
			{
				return false;
			}
		}
		right = vector<int>(sequence.begin() + left.size(), sequence.end() - 1);
		if (left.size() + right.size() != sequence.size() - 1)
		{
			return false;
		}

		return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
	}
};