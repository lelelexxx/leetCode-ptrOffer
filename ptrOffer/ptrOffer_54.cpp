
//54： 求二叉搜索树的第k小节点 ， 中序遍历到第K个
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k<1)
			return NULL;
		stack<TreeNode* > s;
		TreeNode* cur;
		vector<TreeNode *> temp;

		while (true)
			if (pRoot != NULL) {
				s.push(pRoot);
				pRoot = pRoot->left;
			}

			else if (!s.empty()) {
				cur = s.top();
				s.pop();
				temp.push_back(cur);
				if (temp.size() == k)
					return temp[k - 1];
				pRoot = cur->right;
			}
			else break;
			return NULL;
	}


};