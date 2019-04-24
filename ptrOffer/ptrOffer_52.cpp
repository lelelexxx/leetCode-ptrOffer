
//52. 相交链表的第一个公共节点

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//设链表1到公共节点的距离为a,链表2到公共节点的距离为b，公共段长度为c
//则，a+b+c = c+b+a，那么只要在一个链表走到头后，接着走另一个链表，最终就会相等
//如果两个链表没有公共节点，则会list1 == list2 == NULL,返回null
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