
#include<string>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
//38.字符串的全排列。
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
class Solution {
public:
	vector<string> Permutation(string str) {

		string temp;
		vector<string> res;
		if (str.length() == 0)
			return res;
		int length = str.length();
		permutationSub(str, temp, res, length);
		set<string> res_s(res.begin(), res.end()); //借助set去重
		res.assign(res_s.begin(), res_s.end());
		return res;

	}
	void permutationSub(string str, string& temp, vector<string>& res, int length)
	{
		if (temp.length() == length)
		{
			res.push_back(temp);  //达到长度则把当前结果放入res中去

		}
		for (int i = 0; i<str.length(); i++)
		{
			char c = str[i];
			temp.push_back(c);
			str.erase(i, 1);
			permutationSub(str, temp, res, length);
			str.insert(i, 1, c); //回溯时不仅要把删掉的元素插回来，也得把插入temp的元素删除。
			temp.pop_back();
		}


	}
};
int main()
{
	Solution kk;
	string input_{ "aa" };
	vector<string> res;

	res = kk.Permutation(input_);
	set<string> set_s(res.begin(), res.end());
	for (auto x : set_s)
		cout << x << ',';
	cout << endl;
}