//395 ������K���ظ��ַ�����Ӵ�
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
			count[s.at(i) - 'a'] ++;  //ʹ��һ��count����¼ÿ���ַ����ֵĴ���
		}

		while (p<s.size() && count[s.at(p) - 'a'] >= k) p++; //�ҵ���һ�����ִ���С��k���ַ�
		if (p == s.size()) return s.size();//���û�ҵ�����ô��������s�ĳ���

		int left = longestSubstring(s.substr(0, p), k); //���ݵ�һ���ҵ��ĳ��ִ���С��k���ַ����ֿ����ݹ顣
														// ���ִ�������k���ַ������ܳ�������Ӵ��С�
		int right = longestSubstring(s.substr(p + 1), k);

		return max(left, right);

	}
};