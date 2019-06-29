/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
/*
递归做法
*/
#if 1
/*
	思想;倒着想，每次保证l1指向是最小的，返回给上一层,要考虑特殊情况
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		if(l1->val > l2->val)  //交换两个指针，保证l1最小
		{
			ListNode* temp = l1;
			l1 = l2;
			l2 = temp;
		}
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
};
#endif
 
#if 0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        //采用归并排序的思想
        ListNode* ret = new ListNode(0);
        
        ListNode* head = ret;  //不能使用head = ret->next为空指针，因为空指针任意，之后改变ret后并不能让head指向的内容改变
        
        while((l1 != NULL) && (l2 != NULL))
        {
            if((l1->val) <= (l2->val))
            {
                ListNode* temp = new ListNode(l1->val);
                ret->next = temp;
                ret = ret->next;
                l1 = l1->next;
            }
            else
            {
                ListNode* temp = new ListNode(l2->val);
                ret->next = temp;
                ret = ret->next;
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL)
        {
            ListNode* temp = new ListNode(l1->val);
            ret->next = temp;
            ret = ret->next;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            ListNode* temp = new ListNode(l2->val);
            ret->next = temp;
            ret = ret->next;
            l2 = l2->next;
        }
        
        return head->next;
    }
};
#endif

