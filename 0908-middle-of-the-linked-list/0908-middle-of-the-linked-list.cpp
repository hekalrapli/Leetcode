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
    ListNode* middleNode(ListNode* head) {
        int totalNode = 0;
        ListNode *res = head;
        while(res != NULL) {
            totalNode++;
            res = res ->next;
        }
        if(totalNode % 2 != 0) {
            ListNode *temp = head;
            int i = 0;
            while(i != totalNode / 2) {
                temp = temp->next;
                i++;
            }
            return temp;
        }else {
              ListNode *temp = head;
            int i = 0;
            while(i != (totalNode / 2)) {
                temp = temp->next;
                i++;
            }
            return temp;

        }
   
     
        
    }
};