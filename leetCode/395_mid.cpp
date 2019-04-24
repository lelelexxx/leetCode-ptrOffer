//395 至少有K个重复字符的最长子串
//
//
class Solution {
public:
	int longestSubstring(string s, int k) {
		int p = 0;
		vector<int> count(26, 0);
		int res = 0;
		for (int i = 0; i<s.length(); i++)
		{
			count[s.at(i) - 'a'] ++;  //使用一个count来记录每个字符出现的次数
		}

		while (p<s.size() && count[s.at(p) - 'a'] >= k) p++; //找到第一个出现次数小于k的字符
		if (p == s.size()) return s.size();//如果没找到，那么返回整个s的长度

		int left = longestSubstring(s.substr(0, p), k); //根据第一个找到的出现次数小于k的字符，分开，递归。
														// 出现次数少于k的字符不可能出现在最长子串中。
		int right = longestSubstring(s.substr(p + 1), k);

		return max(left, right);

	}
};