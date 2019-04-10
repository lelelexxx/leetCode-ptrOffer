
//4����ά�����еĲ��ң�easy�������Ͻǿ�ʼ�����ų�
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.size() == 0)
			return false;
		int rows = array.size();
		int cols = array[0].size();
		int col = cols - 1;
		int row = 0;
		while ((col >= 0) && (row<rows))
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				col--;
			else
				row++;
		}
		return false;
	}
};