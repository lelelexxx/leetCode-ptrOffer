//53.在排序数组中查找某个数出现的次数,两种解法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//使用stl标准库

class Solution2 {
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		auto pair = equal_range(data.begin(), data.end(), k);
		return pair.second - pair.first;
	}
};
// 分别查找左右边界
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0)
			return 0;
		int start = 0;
		int end = data.size() - 1;
		int left = -1, right = -1;
		while (start<end)
		{
			int mid = start + ((end - start) >> 1);
			if (data[mid] >= k)
			{
				end = mid;
			}
			else if (data[mid] < k)
			{
				start = mid + 1;
			}

		}
		if (data[start] == k)
			left = start;
		start = 0; end = data.size() - 1;
		while (start<end)
		{
			int mid = start + ((end - start) >> 1) + 1;  //查找右边界，mid得向上取整。
												         //不然当，mid == start, 的时候，mid, start, end永远得不到更新，会进入死循环。
			if (data[mid] > k)
			{
				end = mid - 1;
			}
			else if (data[mid] <= k)
			{
				start = mid;
			}

		}
		if (data[end] == k)
			right = end;

		return right == -1 ? 0 : right - left + 1;
	}
};



int main()
{
	vector<int> x{ 2,2,2,2,2,2,2,2,2,2 };
	Solution k;
	int res = k.GetNumberOfK(x,2);
	cout << res << endl;
}