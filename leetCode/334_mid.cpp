//334����������Ԫ������
//̰�ķ���ά������ֵ��һ���ǵ�ǰ�����е���Сֵmin_,��һ�����ǵ�ǰ�����д���min_����Сֵmax_����Ҫ��֤max_��min_֮��
//����������������max_ʱ���򷵻�true��
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size()<3)
			return false;
		int min_ = INT_MAX;
		int max_ = INT_MAX;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] < min_)	//������Сֵ
			{
				min_ = nums[i];
			}
			else if (nums[i] > min_ && nums[i] < max_) //��������������min_����С��max_�������max_.
			{
				max_ = nums[i];
			}
			else if (nums[i] > max_)
				return true;

		}
		return false;
	}
};