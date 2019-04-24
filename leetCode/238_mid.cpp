//238  �����������������ĳ˻�
/*��������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���

ʾ��:

����: [1,2,3,4]
���: [24,12,8,6]*/

//�ȽϺ�����д����ʹ��left��right����vector����һ����������ĳ˻������ұ����ĳ˻�������������vector��˾���
//�����ڿռ��Ͻ����Ż���left��rightʹ�����������д��棬�����Ż���o(n)�ռ�(ֻ��洢���ص�vector)��
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> left(nums.size(), 0);
		vector<int> right(nums.size(), 0);
		vector<int> res(nums.size(), 0);
		for (int i = 0; i<nums.size(); i++)
		{
			if (i == 0)
				left[i] = 1;
			else
			{
				left[i] = left[i - 1] * nums[i - 1];
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (i == nums.size() - 1)
				right[i] = 1;
			else {
				right[i] = right[i + 1] * nums[i + 1];
			}
		}
		for (int i = 0; i<nums.size(); i++)
		{
			res[i] = left[i] * right[i];
		}
		return res;
	}
};