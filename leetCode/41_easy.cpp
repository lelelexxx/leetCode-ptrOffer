//41.缺失的第一个正数
//
/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1, 2, 0]
	输出 : 3
	示例 2 :

	输入 : [3, 4, -1, 1]
	输出 : 2
	示例 3 :

	输入 : [7, 8, 9, 11, 12]
	输出 : 1
	*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {

		for (int i = 0; i<nums.size(); i++)
		{
			while (nums[i] <= nums.size() && nums[i]>0 && nums[i] != nums[nums[i] - 1]) //先将每个数和每个数的下标匹配起来。
			{
				swap(nums[i], nums[nums[i] - 1]);
			}

		}
		for (int i = 0; i<nums.size(); i++)//第一个不匹配的数，就是答案
		{
			if (nums[i] - 1 != i)
				return i + 1;
		}

		return nums.size() + 1;
	}
};