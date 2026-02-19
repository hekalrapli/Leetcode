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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0; i < arr.size()-1; i+=2) {
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
        ListNode * res = new ListNode(arr[0]);
        ListNode *tmpTwo = res;
        for(int i = 1; i < arr.size(); i++) {
            ListNode* new_temp = new ListNode(arr[i]);
            tmpTwo->next = new_temp;
            tmpTwo = tmpTwo->next;
        }
        return res;
    }
};