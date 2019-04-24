//240  搜索二维矩阵2
/*编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。*/

//从右上角开始，逐行逐列排除，可以用二分查找进一步优化。
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int rows = matrix.size();
		int cols = matrix[0].size();

		int row = 0;
		int col = cols - 1;
		while (row<rows && col<cols  && col >= 0) //别忘了判断col是否小于0;
		{
			if (matrix[row][col] == target)
			{
				return true;
			}
			else if (matrix[row][col] > target)
			{
				col--;
			}
			else
				row++;
		}
		return false;
	}
};