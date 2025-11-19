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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL  && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode*res = head;
        while(res != NULL && res->next!= NULL) {
            if(res->next->val == val) {
             ListNode* temp = res->next;
             res->next = temp->next;
             delete temp;
            }else {
                res = res->next;
            }
        }

        return head;
    }
};