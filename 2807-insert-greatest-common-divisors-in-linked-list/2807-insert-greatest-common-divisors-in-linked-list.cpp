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
    
    int gcd(int a, int b) {

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b) {
        return a;

    }

   
    if (a > b)
      return gcd(a - b, b);

    return gcd(a, b - a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) {
            return head;
        }else {
            ListNode *curr = head;
            ListNode *nxt = head;
            while(curr ->next != NULL) {
            nxt = nxt->next;
            ListNode *temp = new ListNode();
            temp->val = gcd(curr->val, curr->next->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = nxt;

            }
        }
        return head;
    }
};