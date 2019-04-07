//32���ֲ��ӡ������������������������һ����ж��²��м�������ڶ����
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