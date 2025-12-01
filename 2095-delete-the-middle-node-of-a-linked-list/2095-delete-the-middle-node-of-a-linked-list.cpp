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

    int count(ListNode *temp) {
        int total = 0;
        while(temp != NULL) {
            total++;
            temp = temp->next;
        }
        return total;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev= NULL;
        ListNode *nxt = head;
        int size =  count(head);
        int i = 0;
        if(size == 1) {
            return NULL;
        }else {
            while(curr != NULL) {
            nxt = nxt ->next; 
            if(i == size/2) {
                prev->next = curr->next;
                delete curr;
            }
            i++;
            prev = curr;
            curr = nxt;
        }
        }
        

        return head;
        
        
    }
};