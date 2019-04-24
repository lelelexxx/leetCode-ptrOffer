//238  除自身以外所有数的乘积
/*给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]*/

//比较好理解的写法，使用left和right两个vector保存一个数左边数的乘积和它右边数的乘积。最后把这两个vector相乘就行
//可以在空间上进行优化，left和right使用两个数进行代替，可以优化到o(n)空间(只需存储返回的vector)。
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