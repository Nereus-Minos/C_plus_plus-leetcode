 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
  
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
        int carry = 0;  //进位符
        
        ListNode* temp = l1;
        
        while(l2 != NULL)
        {
            if(carry == 0)
                temp->val += l2->val;
            else
                temp->val = temp->val + l2->val + 1;
            if(temp->val>9)
            {
                carry = 1;
                temp->val = (temp->val) % 10;
            }
            else
                carry = 0;
            
            if( temp->next == NULL && (l2->next != NULL || carry == 1) )
            {
                if(carry == 1)
                {
                    carry = 0;
                    temp->next = new ListNode(1);
                }
                else  
                    temp->next = new ListNode(0);
            }
            temp = temp->next;
            l2 = l2->next;
        }
        while(temp != NULL)
        {
            if(carry == 0)
                return l1;
            else
                temp->val += 1;
            if(temp->val>9)
            {
                carry = 1;
                temp->val = (temp->val) % 10;
            }
            else
                return l1;
            if( temp->next == NULL && (carry == 1) )
            {
                temp->next = new ListNode(1);
                return l1;
            }
                
            temp = temp->next;
        }
        
        return l1;
    }
};



#if 0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //将空指针直接赋值给指针时，是值传递，函数里面拿到的也仅仅是一个拷贝指针，不会修改原指针的。如果我们想修改原指针而不是指针的副本，就需要传递指针的指针。
        ListNode* ret = NULL;
        ListNode** tempNode = &ret;
        int temp;
        
        while(l1 != NULL && l2 != NULL)
        {
            temp = l1->val +l2->val;
            l1 = l1->next;
            l2=l2->next;
        
            if((*tempNode) != NULL)
            {
                if( ((*tempNode)->val + temp) >19 )
                {
                    (*tempNode)->val = (*tempNode)->val + temp -20;
                    (*tempNode)->next = new ListNode(2);
                }
                else if( ( ((*tempNode)->val + temp) <= 19 ) && ( ( (*tempNode)->val + temp) > 9 ))
                {
                    (*tempNode)->val = (*tempNode)->val + temp -10;
                    (*tempNode)->next = new ListNode(1);
                }
                 else
                    (*tempNode)->val = (*tempNode)->val + temp;
            }
            
            else
            {
               if(temp >9)
                {
                        (*tempNode) = new ListNode(temp-10);
                        (*tempNode)->next = new ListNode(1);
                }
                else
                    (*tempNode) = new ListNode(temp);
            }
            tempNode = &((*tempNode)->next);
        }
     
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                temp = l1->val;
                l1 = l1->next;
            }
                
            else if(l2 != NULL)
            {
                temp = l2->val;
                l2=l2->next;
            }
                
            if((*tempNode) != NULL)
            {
               if(temp + ((*tempNode)->val) >9)
                {
                        (*tempNode)->val = (*tempNode)->val + temp -10;
                        (*tempNode)->next = new ListNode(1);
                }
                else
                    (*tempNode) = new ListNode(temp+ ((*tempNode)->val) );
            }
            else
            {
                if(temp >9)
                {
                        (*tempNode) = new ListNode(temp-10);
                        (*tempNode)->next = new ListNode(1);
                }
                else
                    (*tempNode) = new ListNode(temp);
            }
            tempNode = &((*tempNode)->next);
        }
        
        return ret;
    }
};

#endif
