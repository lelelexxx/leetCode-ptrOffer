
//45:把数组排成最大的数
//由于是大数，需要用string进行返回，不然会溢出。
//string中有很多好用的函数，并且重载了<,>,+，=等运算符。
//c++11中新增了 std::to_sting()函数，可以将很多不同类型转换成string。
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> num_string;

		for (auto i = numbers.begin(); i != numbers.end(); i++)
		{
			cout << *i << endl;
			num_string.push_back(to_string(*i));
		}

		sort(num_string.begin(), num_string.end(), comPare);

		string res;
		for (auto i = num_string.begin(); i != num_string.end(); i++)
			res += *i;
		return res;
	}

	static bool comPare(string s1, string s2)//这里要将自定义比较函数定义为全局或者类内的静态函数。不然sort会找不到。
	{
		if ((s1 + s2)>(s2 + s1))
		{
			return true;
		}
		return false;

	}
};


int main()
{
	string a{ "123" };
	string b{ "321" };
	int c = 345;
	vector<int> t{ 1,2,3,4,5,6,6,7,8 };
	Solution solution;
	string res;
	res = solution.PrintMinNumber(t);
	cout <<  (a < b) << endl;
	cout << (a + b) << endl;
	cout << (a + b + to_string(c)) << endl;
	cout << res << endl;
}
