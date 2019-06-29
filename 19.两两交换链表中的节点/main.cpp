
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        swap(head, head->next);
        swapPairs(head->next->next);
        return head;
    }
    
private:
    void swap(ListNode* node1, ListNode* node2){
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
    
};
