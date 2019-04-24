//334，递增的三元子序列
//贪心法，维护两个值，一个是当前序列中的最小值min_,另一个则是当前序列中大于min_的最小值max_，且要保证max_在min_之后。
//当接下来的数大于max_时，则返回true；
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size()<3)
			return false;
		int min_ = INT_MAX;
		int max_ = INT_MAX;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] < min_)	//更新最小值
			{
				min_ = nums[i];
			}
			else if (nums[i] > min_ && nums[i] < max_) //当新来的数大于min_，且小于max_，则更新max_.
			{
				max_ = nums[i];
			}
			else if (nums[i] > max_)
				return true;

		}
		return false;
	}
};