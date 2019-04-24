//384  ��������
//ϴ���㷨����ĩβԪ����ǰ������Ԫ�ػ�����ʹ��һ��vector����ԭʼ���롣

class Solution {
private:
	vector<int> v_origin;

public:
	Solution(vector<int>& nums) :v_origin(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v_origin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(v_origin);
		for (int i = v_origin.size() - 1; i>0; i--)
		{
			int index = rand() % (i + 1);
			swap(res[i], res[index]);
		}
		return res;
	}
};
