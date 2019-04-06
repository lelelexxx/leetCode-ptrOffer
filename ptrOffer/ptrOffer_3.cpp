//3.�ҳ��������ظ�����
// ����Ϊn������������е�������0~n-1��Χ�ڡ��ҳ�����һ���ظ���

#include<iostream>
#include<vector>

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr)
		{
			return false;
		}
		for (int i = 0; i<length; i++)
			while (i != numbers[i])
			{

				int temp = numbers[i];
				if (temp == numbers[temp])
				{
					//ע�⣬���ﲻ��duplication = &temp, ��ΪtempΪ��ʱ����������ʱ�ᱻ�ͷš�
					//Ҳ����д��duplication = &numbers[i],Ϊɶ�أ�
					*duplication = numbers[i];
					return true;
				}
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		return false;
	}
};

int main()
{
	Solution* s = new Solution();
	int num[]{ 3,1,2,0,2,5,3 };
	int* res = new int;
	bool ans = s->duplicate(num, 7, res);

	std::cout << *res << "," << ans << std::endl;
	delete s;
}