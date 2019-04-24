//350  ��������Ľ���
//������349���ƣ����Ǵ�����Ҫ����ظ�Ԫ�ء�349���ظ�Ԫ��ֻ��Ҫ���һ����


class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> hash_;
		for (int i = 0; i<nums1.size(); i++)
		{
			if (hash_.find(nums1[i]) == hash_.end())
			{
				hash_[nums1[i]] = 0;
			}
			else
			{
				hash_[nums1[i]] ++;
			}

		}
		for (int i = 0; i<nums2.size(); i++)
		{
			if (hash_.find(nums2[i]) != hash_.end() && hash_[nums2[i]] >= 0)
			{
				res.push_back(nums2[i]);
				hash_[nums2[i]] --;
			}
		}
		return res;
	}
};