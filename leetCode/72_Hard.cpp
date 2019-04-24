
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//72 编辑距离
//给定两个单词，计算出将word1转换成word2所使用的最小操作数。
//可以进行插入，删除，替换

int minDistance(string word1, string word2) {
    
    //状态定义: dp[i][j]，从word1的第1个到第i个字符串-》转换成word2的第1个到第j个所需最少次数
    //初始状态: dp[0][j] = j, dp[i][0]= i
    //递推关系: dp[i][j] = 
    // if word1[i]== word2[j] : dp[i][j] = dp[i-1][j-1]
    // if word1[i]!= word2[j] : dp[i][j] = min(dp[i-1][j-1] + 1, dp[i-1][j]+1, dp[i][j-1]+1 )
        
    //dp[i-1][j-1] + 1 ，即word1[i-1]->word2[j-1], 然后用word2[j]替换word1[i]。需要一次修改
    //dp[i-1][j] + 1, 即word1[i-1]->word2[j], 然后将word1[i]删去。 需要一次修改
    //dp[i][j-1] + 1, 即word1[i]->word2[j-1]， 则将word2[j]插入到word1[i]后面。需要一次修改  
        
    int rows = word1.size();
    int cols = word2.size();
    vector<vector<int> > dp(rows+1, vector<int>(cols+1));
        
    for(int i = 0; i<=rows; i++ )
        dp[i][0] = i;
    for(int j = 0; j<=cols; j++)
        dp[0][j] = j;
        
    for (int i=1; i<=rows; i++)
        for(int j=1;j<=cols; j++)
        {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min((dp[i-1][j-1]+1), min((dp[i-1][j]+1), (dp[i][j-1]+1)));
        }
        
    return dp[rows][cols];
}

int main()
{
	string  target, ori;
	cin >> target;
	cin >> ori;
	
	int res = minDistance(target, ori);
	cout << res;

}