#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool match(char* str, char* pattern);
bool matchSub(char* str, char* pattern, int i, int j);
//递归方法， 容易出现堆溢出
bool match(char* str, char* pattern)
{
	return matchSub(str, pattern, strlen(str) - 1, strlen(pattern) - 1);//从后往前匹配

}

bool matchSub(char* str, char* pattern, int i, int j)
{
	if (j == -1)	//都到头了，返回true
					//只有模式串到头了，匹配失败，返回false
		if (i == -1)
			return true;
		else return false;

		if (pattern[j] == '.' || pattern[j] == str[i]) //尾部匹配成功
			return matchSub(str, pattern, i - 1, j - 1);//一起去掉尾部进行匹配

		if (pattern[j] == '*')	//模式串尾部为'*'，
		{
			if ((i>-1) && (pattern[j - 1] == str[i] || pattern[j - 1] == '.')) //当前尾部能够用‘a*’匹配成功，则匹配掉str的尾部
				if (matchSub(str, pattern, i - 1, j))	//去掉str被匹配掉的尾部
					return true;
			return matchSub(str, pattern, i, j - 2);//*匹配前一个元素0次，相当于删掉模式串尾部的'a*'
		}
		return false;

}
//动态规划方法,
class Solution {
public:
	bool isMatch(string str, string pattern)
	{
		//状态定义：dp[i][j] , str[0:i-1] 与 pattern[0:j-1]能够匹配成功。(从空串开始)
		//初始状态：dp[0][0] = true;
		// dp[i][0] = i>0 ? false; 模式串为空只能匹配空串
		// dp[0][j] = j>1? 
		// if j>1 :dp[0][j] = dp[0][j-2] && pattern[j-1] == '*' //只能是当前模式串尾部为'*'，通过匹配零次的性质消除前面的。
		
		//递推关系: 
		//if pattern[j - 1] == '.' or pattern[j - 1] == str[i - 1]  模式串尾部为'.' 或者两个串的尾部相同，这个时候就可以将前一个状态传递下来。
		//	dp[i][j] = dp[i-1][j-1]
		// if pattern[j-1] == '*' : dp[i][j] = dp[i][j-2] || (str[i-1] == pattern[j-2] or pattern[j-2]=='.') && dp[i-1][j];
							//*可以前面的字符0次 || *匹配前面字符1次  满足前面两个之一的，就可以将dp[i-1][j]的状态传递下来。
							//															（这里其实对应的是'*'匹配前一个字符多次，因为我们的状态由前往后传递而来，
																						//即只要当前str尾部字符能够被匹配掉，那么这个状态就可以继续传递下去）
		int rows = str.length();
		int cols = pattern.length();
		vector<vector<bool>> dp(rows + 1, vector<bool>(cols + 1, false));

		dp[0][0] = true;
		for (int i = 1; i <= rows; i++)
			dp[i][0] = false;
		for (int j = 1; j <= cols; j++)
		{
			dp[0][j] = (j>1) && (pattern[j - 1] == '*') && dp[0][j - 2];
		}

		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= cols; j++)
			{
				if (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1])
					dp[i][j] = dp[i - 1][j - 1];

				if (pattern[j - 1] == '*')
				{	
					//下面这段也可以写成  dp[i][j] = dp[i][j-2] || (str[i-1] == pattern[j-2] or pattern[j-2]=='.') && dp[i-1][j] ;
					//下面这种分开写法可能更好理解，
					//先处理当前*能否匹配掉str中的尾部元素，把能够匹配成功的情况或起来。
					//再处理，当前*不能匹配掉尾部元素，则只能匹配前一个字符0次（相当于把前一个字符删掉）
					if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
						dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
					//dp[i][j] = 匹配前一个字符0次|| 匹配前一个字符1次 || 匹配前一个字符多次
					else
						dp[i][j] = dp[i][j - 2];// a* 只能匹配0次
				}

			}



		return dp[rows][cols];
	}
};

int main()
{
	char* a = "fucking eidot";
	cout << a[3] << endl;
	cout << strlen(a) << endl;
	string str{ "fffffff" };
	char*p = (char*)str.data();

	cout << *p << endl;
	//char* s = "aasdfasdfasdfasdfas";
	//char* p = "aasdf.*asdf.*asdf.*asdf.*s";

	//cout << match(s,p) << endl;
}