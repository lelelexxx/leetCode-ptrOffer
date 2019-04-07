//32：分层打印二叉树，即层序遍历，输出完一层后，判断下层有几个结点在队列里。
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> >  res;
		if (pRoot == NULL)
		{
			return res;
		}
		queue<TreeNode*> st;
		vector<int> temp;
		st.push(pRoot);
		int layerCount = 1;
		while (!st.empty())
		{
			TreeNode* current = st.front();
			st.pop();
			temp.push_back(current->val);
			layerCount--;
			if (current->left != NULL)
				st.push(current->left);
			if (current->right != NULL)
				st.push(current->right);
			if (layerCount == 0)
			{
				layerCount = st.size();
				res.push_back(temp);
				temp.clear();
			}
		}
		return res;
	}

};