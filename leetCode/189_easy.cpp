/*189 ��ת����
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: [1,2,3,4,5,6,7] �� k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]*/
//˼·�� ��ȫ��reverse����������͵�ǰ�����ˣ�Ȼ�������ת�㣬�ֱ�reverseǰ�벿�ֺͺ�벿�֣���˳�ֲ�˳��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k>nums.size())			//��k>nums��ʱ����Ҫ������Ȼ�����
			k = k%nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};