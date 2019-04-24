//124.�����������·����
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
private:
	int max_;
public:
	int maxPathSum(TreeNode* root)
	{
		max_ = -INT_MAX;
		int res = maxPathSumSub(root);
		return max_;
	}
	int maxPathSumSub(TreeNode* root) {
		if (root == NULL)
			return 0;
		int maxleft = maxPathSumSub(root->left);
		int maxright = maxPathSumSub(root->right);
		vector<int> v;
		v.push_back(root->val);   //����ÿ���ڵ���˵�����ֵ�����ǵ�������ڵ�
		v.push_back(maxleft + root->val);//������������+��ǰ�ڵ�
		v.push_back(maxright + root->val);//������������+��ǰ�ڵ�
		v.push_back(maxleft + maxright + root->val);//�������������ͼӵ�ǰ�ڵ�
		v.push_back(max_);
		max_ = *max_element(v.begin(), v.end());//����ݹ�����е����ֵ

		return *max_element(v.begin(), v.begin() + 3);//���ϻ��ݣ���ô�Ͳ����������������ͼӵ�ǰ�ڵ�,�����ų������ڶ��

	}
};