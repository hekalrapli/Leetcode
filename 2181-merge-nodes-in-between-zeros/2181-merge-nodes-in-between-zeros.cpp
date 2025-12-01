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

   ListNode* mergeNodes(ListNode* head) {
        ListNode *result = new ListNode();
        ListNode *tmp = result;
        ListNode *curr = head;
        long long temp = 0;
        curr = curr->next;
        while(curr != NULL) {
            if(curr ->val == 0 ) {
                ListNode *helper = new ListNode();
                helper->val = 0;
                tmp->val = temp;
                tmp->next = helper;
                tmp = helper;
                temp = 0;
               
                
            }else {
                temp += curr->val;
            }
            curr = curr->next;
        }
    ListNode *tempo = result;
    ListNode *prev;
    while(tempo->next != NULL) {
        prev = tempo;
        tempo = tempo->next;
    }
    delete tempo;
    prev->next = NULL;
    return result;
        
        
    } 
};