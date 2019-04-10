
//7���ؽ���������Ҫ�ؽ�������������������������ǰ��Ӻ����޷��ָ���������
//��ǰ�����ȷ�����ڵ㣬�ٴ��������ҳ��������������������������
//�ٸ�����������������������������г��ȣ��ҳ�����������ǰ�������Ȼ��ݹ�ͺ��ˡ�ע������˵ݹ����
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