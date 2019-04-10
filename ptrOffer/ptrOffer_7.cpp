
//7：重建二叉树。要重建二叉树，必须得有中序遍历。前序加后序无法恢复二叉树。
//靠前序遍历确定根节点，再从中序中找出左子树和右子树的中序遍历。
//再根据左子树和右子树的中序遍历序列长度，找出左右子树的前序遍历。然后递归就好了。注意别忘了递归基。
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;
		TreeNode* res = new TreeNode(pre[0]);
		auto vinRoot = find(vin.begin(), vin.end(), pre[0]);
		vector<int> leftVin(vin.begin(), vinRoot);
		vector<int> rightVin(vinRoot + 1, vin.end());
		int lenLeft = leftVin.size();
		int lenRight = rightVin.size();
		vector<int> leftPre(pre.begin() + 1, pre.begin() + lenLeft + 1);
		vector<int> rightPre(pre.begin() + lenLeft + 1, pre.end());
		res->left = reConstructBinaryTree(leftPre, leftVin);
		res->right = reConstructBinaryTree(rightPre, rightVin);

		return res;

	}
};