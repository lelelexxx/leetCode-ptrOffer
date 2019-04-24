#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//leetcode  , 用最少数量的箭引爆气球
//将坐标按照second，从小到大排序，贪心
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0)
			return 0;

		int res = 1;
		
		sort(points.begin(), points.end(), cmp);
		int temp_end = (*points.begin()).second;
		for (int i = 1; i<points.size(); i++)
		{

			if (points[i].first <= temp_end)
				continue;
			else
			{
				res++;
				temp_end = points[i].second;
			}
		}
		return res;


	}
	static bool cmp(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.second == p2.second)
			return p1.first<p2.first;
		return p1.second<p2.second;
	}
};

int main()
{
	Solution a;
	vector<pair<int, int>> x{ {9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7} };
	int res = a.findMinArrowShots(x);
	cout << res << endl;

}