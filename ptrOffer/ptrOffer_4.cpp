
//4：二维数组中的查找，easy，从右上角开始逐行排除
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