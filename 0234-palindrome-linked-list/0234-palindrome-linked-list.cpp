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
    int total(ListNode *head) {
        int total = 0;
        while(head != NULL) {
            total++;
            head = head->next;
        }
        return total;
    }
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        int size = total(head)/2;
        int cap = total(head);
       
 
         while(size > 0) {
            st.push(head->val);
            head = head->next;
            size--;
        }
        if(cap % 2 != 0) {
            head = head->next;
        } 
        while(head != NULL) {
            if(head-> val == st.top()) {
                st.pop();
            }
            head = head->next;
        }
        
        if(st.empty() ) return true;
        else return false;
        
        
    }
};