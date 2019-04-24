//240  ������ά����2
/*��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target���þ�������������ԣ�

ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
ʾ��:

���о��� matrix ���£�

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target = 5������ true��*/

//�����Ͻǿ�ʼ�����������ų��������ö��ֲ��ҽ�һ���Ż���
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int rows = matrix.size();
		int cols = matrix[0].size();

		int row = 0;
		int col = cols - 1;
		while (row<rows && col<cols  && col >= 0) //�������ж�col�Ƿ�С��0;
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