//2.两数相加
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 80

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp;
        int up = 0;
        ListNode* pre;
        ListNode* head = l1;
        while(l1!=NULL && l2!=NULL)
        {
            temp = l1->val+l2->val+up;
            l1->val = temp%10;
            up = temp/10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if( l1 == NULL)
            pre->next = l2;  // l1的长度小于l2，就把l2剩下的接过来
        l1 = pre->next;
        while (l1 != NULL)
        {
            temp = l1->val + up;
            l1->val = temp%10;
            up = temp/10;
            pre = l1;
            l1 = l1->next;
        }
        if(up>0)
        {
            ListNode * high = new ListNode(up);
            pre->next = high;
        }
        return head;
        
    }
};