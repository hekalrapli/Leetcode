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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head;
        vector<int> arr;
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> res(arr.size(), 0);
        if(k  > 0 && head != NULL) {
            k = k % arr.size();
            for(int i = 0; i < arr.size(); i++) {
            int idx = (i+k) % arr.size();
            res[idx] = arr[i];
            }
            ListNode *new_res = new ListNode(res[0]);
            ListNode *cnt = new_res;
            for(int i = 1; i < res.size(); i++) {
                ListNode *tempo = new ListNode(res[i]);
                cnt ->next = tempo;
                cnt = cnt->next;
            }
            return new_res;
        }else {
            return head;
        }
   
    }
};