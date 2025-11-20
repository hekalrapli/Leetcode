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
    int count(ListNode* x) {
        int total = 0;
        while(x != NULL) {
            total++;
            x = x->next;
        }
        return total;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *pre;
        int size = count(temp) -n +1;
        int i = 1;
        while(i < size && temp != NULL) {
            pre = temp;
            temp = temp -> next;
            i++;
        }
        if(pre != NULL) {
        pre->next = temp->next;
        delete temp;
        }else if( size == 1) {
            head = head ->next;
        }
        return head;
    }
};