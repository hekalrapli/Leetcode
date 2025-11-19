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
    int num(ListNode *head) {
        int total = 0;
        while(head != NULL) {
            total++;
            head = head->next;
        }
        return total;
    }
    int getDecimalValue(ListNode* head) {
        int size = num(head)-1;
        int res = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            res += temp->val * pow(2,size);
            temp = temp->next;
            size--;
        }
        return res;
    }
};