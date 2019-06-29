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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k==0 || k == 1 || head == NULL)
            return head;
        
        ListNode* temp = head;
        for(int i = 0; i < k-1; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                return head;
        }
        
        swap(head, temp);
        reverseKGroup(temp->next, k);
        
        temp = head->next;
        
        while( (k-1) > 0)
        {
            k = k-2;
           innerGroup(temp, k);
            temp = temp->next;
        }
        return head;
    }
    
private:
    void innerGroup(ListNode* head, int k){
        
        ListNode* temp = head;
        for(int i = 0; i < k-1; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                return ;
        }
        swap(head, temp);
    }
    
    
    void swap(ListNode* node1, ListNode* node2)
    {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
};
