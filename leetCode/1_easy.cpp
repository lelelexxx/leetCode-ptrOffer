//1. two sum 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
        {
            if (hash_.find(nums[i]) != hash_.end())
            {
                res.push_back(hash_[nums[i]]);
                res.push_back(i);
                break;
            }
            hash_[target - nums[i]] = i;
        }
        return res;
    }
};