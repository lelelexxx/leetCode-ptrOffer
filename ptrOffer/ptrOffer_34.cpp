//34,二叉树中和为某一值的路径
// 打印出二叉树中节点值的和为输入整数的所有路径。路径定义为从根节点到叶节点（这样就太简单了吧）
#include<stdio.h>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
void creatTree(vector<int> nums, TreeNode* root)
{
	//todo
}
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		vector<int> temp;
		if (root == nullptr)
			return res;
		FindPathSub(root, expectNumber, temp, res);
		return res;


	}
	//传引用的方式进行递归的增删。类似python传引用

	void FindPathSub(TreeNode* root, int expectNumber, vector<int>& temp, vector<vector<int>>& res)
	{
		if (expectNumber == root->val && root->left == NULL && root->right == NULL)
		{
			temp.push_back(root->val);
			res.push_back(temp);
			temp.pop_back();//因为提前push了root->val，这里就需要多pop一次，不然pop和push次数不对等，回溯会有残留。
			return;
		}
		temp.push_back(root->val);
		if (root->left != NULL)
			FindPathSub(root->left, expectNumber - root->val, temp, res);
		if (root->right != NULL)
			FindPathSub(root->right, expectNumber - root->val, temp, res);
		temp.pop_back();//删除当前点，回溯
	}
};

int main()
{
}