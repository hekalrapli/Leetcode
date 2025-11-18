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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx;
        int i = 1;
        ListNode *pre = NULL;
        while(head != NULL) {
            if(pre != NULL && head-> next != NULL) {
                if(head->val > pre->val && head->val > head->next->val) {
                    idx.push_back(i);
                }else if(head->val < pre->val && head->val < head->next->val) {
                    idx.push_back(i);
                }
            }
            pre = head;
            head = head->next;
            i++;
        }
        if(idx.size() < 2 ) {
            return  {-1,-1};
        }else {
            int minim = 100000;
            for(int i = 0 ; i < idx.size()-1; i++) {
                    minim = min(minim, abs(idx[i] - idx[i+1]));
                
            }
            return {minim ,idx[idx.size()-1] - idx[0]};
        }

    }

};