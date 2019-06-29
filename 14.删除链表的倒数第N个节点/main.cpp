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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //使用双指针，一次遍历， temp1指向要删除的节点的前一个节点
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        int i = 0; //保证temp2移动n次
        //先将temp2移动n个节点
        for(; i<n; i++)
            temp2 = temp2->next;
        
        //此时temp2如果等于NULL，说明删除的是头结点
        if(0 == temp2)
        {
            head = head->next;
            delete temp1;
            return head;
        }
        
        //此时temp1和temp2中间有n个节点,同时移动temp1和temp2
        while((temp2->next) != NULL)
        {
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        //此时temp1则为要删除的节点的前一个节点
        ListNode* deleteNode = temp1->next;
        temp1->next = deleteNode->next;
        delete deleteNode;
        
        return head;
    }
};


#if 0
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //首先找到这个点位置，然后删除
        int count = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        
        temp = head;
        //特殊情况，删除的是头结点
        if(n == count)
        {
            head = head->next;
            delete temp;
            return head;
        }
        
        //
        for(int i = 1; i < count - n; i++)
        {
            temp = temp->next;
        }
         ListNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        
        return head;
    }
};
#endif