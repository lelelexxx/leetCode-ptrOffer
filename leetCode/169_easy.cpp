
//169  ������
//����ͶƱ������ÿ���������Լ�ͶƱ��ÿ��һ������ȵ�������ǰƱ����һ��Ʊ��Ϊ0�󣬻���һ������������ͬ������Ʊ����һ��

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