
//169  求众数
//采用投票方法，每个数都给自己投票，每来一个不相等的数，当前票数减一，票数为0后，换另一个数。遇到相同的数，票数加一。

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		int count = 1;
		int temp = nums[0];

		for (int i = 1; i<nums.size(); i++)
		{
			if (count == 0)
				temp = nums[i];
			if (nums[i] != temp)
				count--;
			else count++;

		}
		return temp;

	}
};