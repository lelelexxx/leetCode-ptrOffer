//124.二叉树的最大路径和
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
		v.push_back(root->val);   //对于每个节点来说，最大值可能是单独这个节点
		v.push_back(maxleft + root->val);//或者其左子树+当前节点
		v.push_back(maxright + root->val);//或者其右子树+当前节点
		v.push_back(maxleft + maxright + root->val);//或者左右子树和加当前节点
		v.push_back(max_);
		max_ = *max_element(v.begin(), v.end());//保存递归过程中的最大值

		return *max_element(v.begin(), v.begin() + 3);//向上回溯，那么就不可能是左右子树和加当前节点,所以排除倒数第二项。

	}
};