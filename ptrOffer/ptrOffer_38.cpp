
#include<string>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
//38.�ַ�����ȫ���С�
//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
//���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
class Solution {
public:
	vector<string> Permutation(string str) {

		string temp;
		vector<string> res;
		if (str.length() == 0)
			return res;
		int length = str.length();
		permutationSub(str, temp, res, length);
		set<string> res_s(res.begin(), res.end()); //����setȥ��
		res.assign(res_s.begin(), res_s.end());
		return res;

	}
	void permutationSub(string str, string& temp, vector<string>& res, int length)
	{
		if (temp.length() == length)
		{
			res.push_back(temp);  //�ﵽ������ѵ�ǰ�������res��ȥ

		}
		for (int i = 0; i<str.length(); i++)
		{
			char c = str[i];
			temp.push_back(c);
			str.erase(i, 1);
			permutationSub(str, temp, res, length);
			str.insert(i, 1, c); //����ʱ����Ҫ��ɾ����Ԫ�ز������Ҳ�ðѲ���temp��Ԫ��ɾ����
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