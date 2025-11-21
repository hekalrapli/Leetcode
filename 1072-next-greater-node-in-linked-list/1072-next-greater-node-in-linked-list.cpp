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

    int len(ListNode *x) {
        ListNode *p = x;
        int total;
        while(p != NULL) {
            total++;
            p = p->next;
        }
        return total;
    }
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> res(len(head),0);
        ListNode *temp = head;
        int index = 0;
        while(temp != NULL) {
            ListNode *next_node = temp->next;
            while(next_node != NULL) {
                if(temp -> val < next_node -> val) {
                    res[index] = next_node ->val;
                    break;
                }else {
                    next_node = next_node ->next;
                }
            }
            index++;
            temp = temp ->next;
        }
        return res;
    }
};