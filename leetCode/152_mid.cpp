//152 
/*����һ���������� nums ���ҳ�һ�������г˻��������������У����������ٰ���һ��������

ʾ�� 1:

����: [2,3,-2,4]
���: 6
����: ������ [2,3] �����˻� 6��
ʾ�� 2:

����: [-2,0,-1]
���: 0
����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int temp = 1;
		int max_res = nums[0];
		for (int i = 0; i<nums.size(); i++) {		//�������ҳ�һ�飬��¼���ֵ
			temp *= nums[i];						//������Ϊż�����������ֵ����������Ļ�
			if (temp>max_res) {					   //������Ϊ����������ô���д������ҳ˵����һ������ �ʹ�������˵����һ��������ȡ���е����ֵ
				max_res = temp;
			}
			if (nums[i] == 0) {
				temp = 1;
			}
		}
		temp = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {//���������һ�飬��¼���ֵ
			temp *= nums[i];
			if (temp>max_res) {
				max_res = temp;
			}
			if (nums[i] == 0) {
				temp = 1;
			}
		}

		return max_res;
	}
};