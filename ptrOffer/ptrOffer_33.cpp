

/*33题：二叉搜索树的后序遍历序列
		判断序列[1,2,3,4,5]是否为二叉搜索树的后序遍历序列。
		要特别注意循环跳出时的指针位置。
		另外，本解法认为输入[]时，应返回True。要返回False可以在这个函数外再套一层函数。
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