/*189 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]*/
//思路： 先全部reverse，后面的数就到前面来了，然后根据旋转点，分别reverse前半部分和后半部分，理顺局部顺序
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k>nums.size())			//当k>nums的时候需要处理，不然会出错。
			k = k%nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};