#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
//leetcode 125  ��֤���Ĵ�
//
class Solution {
public:
	bool isPalindrome(string &s) {

		int left = 0;
		int right = s.length() - 1;
		transform(s.begin(), s.end(), s.begin(), ::tolower);//string��Сдת��
		while (left<right)
		{
			if (isalnum(s[left])&& isalnum(s[right]))//�ж�char����ĸ�������֡�
			{
				if (s[left] == s[right])
				{
					left++;
					right--;
					continue;
				}
				else
					return false;
			}
			while (left<right && !isalnum(s[left]))
				left++;
			while (left<right && !isalnum(s[right]))
				right--;
		}
		return true;
	}
};
int main()
{
	Solution a;
	string s{"A man, a plan, a canal: Panama" };
	bool res = a.isPalindrome(s);
	cout << res << endl;
	cout << s;

}