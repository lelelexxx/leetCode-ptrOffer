
//45:�������ų�������
//�����Ǵ�������Ҫ��string���з��أ���Ȼ�������
//string���кܶ���õĺ���������������<,>,+��=���������
//c++11�������� std::to_sting()���������Խ��ܶ಻ͬ����ת����string��
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

	static bool comPare(string s1, string s2)//����Ҫ���Զ���ȽϺ�������Ϊȫ�ֻ������ڵľ�̬��������Ȼsort���Ҳ�����
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
