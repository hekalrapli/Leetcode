/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp = head;
        ListNode *odd  = NULL;
        ListNode *odd_last = odd;
        ListNode *even = NULL;
        ListNode *even_last = even;
        int index = 1;
        while(temp != NULL) {
        ListNode *nextNode = temp->next;
        temp->next= NULL;
            if(index % 2 != 0)  {
                if(odd == NULL) {
                    odd = temp;
                    odd_last = temp;
                }else {
                odd_last ->next = temp;
                odd_last = temp;
        
                }
            }else {
            
                if(even == NULL) {
                    even = temp;
                    even_last = temp;
                }else {
                even_last ->next = temp;
                even_last = temp;
        
                }
            }
            index++;
            temp = nextNode;
            }
  
    ListNode* p = odd;
    while(p != NULL && p->next != NULL ) {
        p = p ->next;
    }
    if(p != NULL) {
     p->next = even;

    }
        return odd;
        }
    
};