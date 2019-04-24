//152 
/*给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int temp = 1;
		int max_res = nums[0];
		for (int i = 0; i<nums.size(); i++) {		//从左往右乘一遍，记录最大值
			temp *= nums[i];						//若负数为偶数个，则最大值是整个数组的积
			if (temp>max_res) {					   //若负数为奇数个，那么就有从左往右乘到最后一个奇数 和从右往左乘到最后一个奇数。取其中的最大值
				max_res = temp;
			}
			if (nums[i] == 0) {
				temp = 1;
			}
		}
		temp = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {//从右往左乘一遍，记录最大值
			temp *= nums[i];
			if (temp>max_res) {
				max_res = temp;
			}
			if (nums[i] == 0) {
				temp = 1;
			}
		}

		return max_res;
	}
};