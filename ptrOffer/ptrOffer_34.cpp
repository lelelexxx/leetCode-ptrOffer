//34,�������к�Ϊĳһֵ��·��
// ��ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����·������Ϊ�Ӹ��ڵ㵽Ҷ�ڵ㣨������̫���˰ɣ�
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
	//�����õķ�ʽ���еݹ����ɾ������python������

	void FindPathSub(TreeNode* root, int expectNumber, vector<int>& temp, vector<vector<int>>& res)
	{
		if (expectNumber == root->val && root->left == NULL && root->right == NULL)
		{
			temp.push_back(root->val);
			res.push_back(temp);
			temp.pop_back();//��Ϊ��ǰpush��root->val���������Ҫ��popһ�Σ���Ȼpop��push�������Եȣ����ݻ��в�����
			return;
		}
		temp.push_back(root->val);
		if (root->left != NULL)
			FindPathSub(root->left, expectNumber - root->val, temp, res);
		if (root->right != NULL)
			FindPathSub(root->right, expectNumber - root->val, temp, res);
		temp.pop_back();//ɾ����ǰ�㣬����
	}
};

int main()
{
}