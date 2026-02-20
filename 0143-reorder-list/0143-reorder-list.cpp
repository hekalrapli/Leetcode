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
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        vector<int> arr;
        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> arrTemp;
        for(int i = 0; i  < arr.size()/2; i++) {
            arrTemp.push_back(arr[i]);
            arrTemp.push_back(arr[arr.size()-i-1]);
        }
        if(arr.size() % 2 == 1) arrTemp.push_back(arr[arr.size()/2]);
        ListNode *res = new ListNode(arrTemp[0]);
        ListNode *tmp_res = res;
        for(int i = 1; i  < arrTemp.size(); i++){
            ListNode *temp_res = new ListNode(arrTemp[i]);
            tmp_res->next = temp_res;
            tmp_res = tmp_res->next;
        }
        ListNode * new_head = head;
        res = res->next;
        while(res != NULL) {
            new_head->next = res;
            res = res->next;
            new_head = new_head->next;
        }
      
     
    }
};