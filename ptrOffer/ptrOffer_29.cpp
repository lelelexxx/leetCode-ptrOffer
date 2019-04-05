
/*˳ʱ���ӡ����
	����
		[1,2]
		[3,4]
	res = [1,2,4,3]
	
*/

#include<vector>

using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
	int di = 0, dj = 1;
	int i = 0, j = 0;
	vector<int> res;
	if (matrix.size() > 0)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();

		for (int c = 0; c < rows*cols; c++)
		{
			res.push_back(matrix[i][j]);
			matrix[i][j] = 0;
			if (matrix[(i + di) % rows][((j + dj) % cols + cols) % cols] == 0) //tips��c++�� -7%3 = -1 �� python �� -7%3 = 2 
																			   //	��Ϊ c++��Ϊ��0ȡ����pythonΪ����ȡ����
			{																	// -1 = -7 - t��-7/3��*3    2 = -7 - t(-7/3)*3              
				int temp = di;
				di = dj;
				dj = -temp;
			}
			i += di;
			j += dj;
		}

	}
	return res;
}