#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool match(char* str, char* pattern);
bool matchSub(char* str, char* pattern, int i, int j);
//�ݹ鷽���� ���׳��ֶ����
bool match(char* str, char* pattern)
{
	return matchSub(str, pattern, strlen(str) - 1, strlen(pattern) - 1);//�Ӻ���ǰƥ��

}

bool matchSub(char* str, char* pattern, int i, int j)
{
	if (j == -1)	//����ͷ�ˣ�����true
					//ֻ��ģʽ����ͷ�ˣ�ƥ��ʧ�ܣ�����false
		if (i == -1)
			return true;
		else return false;

		if (pattern[j] == '.' || pattern[j] == str[i]) //β��ƥ��ɹ�
			return matchSub(str, pattern, i - 1, j - 1);//һ��ȥ��β������ƥ��

		if (pattern[j] == '*')	//ģʽ��β��Ϊ'*'��
		{
			if ((i>-1) && (pattern[j - 1] == str[i] || pattern[j - 1] == '.')) //��ǰβ���ܹ��á�a*��ƥ��ɹ�����ƥ���str��β��
				if (matchSub(str, pattern, i - 1, j))	//ȥ��str��ƥ�����β��
					return true;
			return matchSub(str, pattern, i, j - 2);//*ƥ��ǰһ��Ԫ��0�Σ��൱��ɾ��ģʽ��β����'a*'
		}
		return false;

}
//��̬�滮����,
class Solution {
public:
	bool isMatch(string str, string pattern)
	{
		//״̬���壺dp[i][j] , str[0:i-1] �� pattern[0:j-1]�ܹ�ƥ��ɹ���(�ӿմ���ʼ)
		//��ʼ״̬��dp[0][0] = true;
		// dp[i][0] = i>0 ? false; ģʽ��Ϊ��ֻ��ƥ��մ�
		// dp[0][j] = j>1? 
		// if j>1 :dp[0][j] = dp[0][j-2] && pattern[j-1] == '*' //ֻ���ǵ�ǰģʽ��β��Ϊ'*'��ͨ��ƥ����ε���������ǰ��ġ�
		
		//���ƹ�ϵ: 
		//if pattern[j - 1] == '.' or pattern[j - 1] == str[i - 1]  ģʽ��β��Ϊ'.' ������������β����ͬ�����ʱ��Ϳ��Խ�ǰһ��״̬����������
		//	dp[i][j] = dp[i-1][j-1]
		// if pattern[j-1] == '*' : dp[i][j] = dp[i][j-2] || (str[i-1] == pattern[j-2] or pattern[j-2]=='.') && dp[i-1][j];
							//*����ǰ����ַ�0�� || *ƥ��ǰ���ַ�1��  ����ǰ������֮һ�ģ��Ϳ��Խ�dp[i-1][j]��״̬����������
							//															��������ʵ��Ӧ����'*'ƥ��ǰһ���ַ���Σ���Ϊ���ǵ�״̬��ǰ���󴫵ݶ�����
																						//��ֻҪ��ǰstrβ���ַ��ܹ���ƥ�������ô���״̬�Ϳ��Լ���������ȥ��
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
					//�������Ҳ����д��  dp[i][j] = dp[i][j-2] || (str[i-1] == pattern[j-2] or pattern[j-2]=='.') && dp[i-1][j] ;
					//�������ַֿ�д�����ܸ�����⣬
					//�ȴ���ǰ*�ܷ�ƥ���str�е�β��Ԫ�أ����ܹ�ƥ��ɹ��������������
					//�ٴ�����ǰ*����ƥ���β��Ԫ�أ���ֻ��ƥ��ǰһ���ַ�0�Σ��൱�ڰ�ǰһ���ַ�ɾ����
					if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
						dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
					//dp[i][j] = ƥ��ǰһ���ַ�0��|| ƥ��ǰһ���ַ�1�� || ƥ��ǰһ���ַ����
					else
						dp[i][j] = dp[i][j - 2];// a* ֻ��ƥ��0��
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