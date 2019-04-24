
//52. �ཻ����ĵ�һ�������ڵ�

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//������1�������ڵ�ľ���Ϊa,����2�������ڵ�ľ���Ϊb�������γ���Ϊc
//��a+b+c = c+b+a����ôֻҪ��һ�������ߵ�ͷ�󣬽�������һ���������վͻ����
//�����������û�й����ڵ㣬���list1 == list2 == NULL,����null
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {

		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		ListNode* list1 = pHead1;
		ListNode* list2 = pHead2;

		while (list1 != list2)
		{
			list1 = list1 == NULL ? pHead2 : list1->next;
			list2 = list2 == NULL ? pHead1 : list2->next;
		}

		return list1;



	}
};