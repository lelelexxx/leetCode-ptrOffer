//3.找出数组中重复的数
// 长度为n的数组中里，所有的数都在0~n-1范围内。找出任意一个重复数

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
					//注意，这里不能duplication = &temp, 因为temp为临时变量，返回时会被释放。
					//也不能写作duplication = &numbers[i],为啥呢？
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