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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *temp = head;
        vector<int> arr;
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp ->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* res = new ListNode(arr[0]);
        ListNode * tmp = res;
        for(int i = 1; i < arr.size(); i++) {
            ListNode *new_node = new ListNode(arr[i]);
            tmp->next = new_node;
            tmp = tmp->next;
        }
        return res;
    }
};