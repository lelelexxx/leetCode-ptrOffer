#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
//leetcode 125  验证回文串
//
class Solution {
public:
	bool isPalindrome(string &s) {

		int left = 0;
		int right = s.length() - 1;
		transform(s.begin(), s.end(), s.begin(), ::tolower);//string大小写转换
		while (left<right)
		{
			if (isalnum(s[left])&& isalnum(s[right]))//判断char是字母或者数字。
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