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

    int count(ListNode *temp) {
        int total = 0;
        while(temp != NULL) {
            total++;
            temp = temp->next;
        }
        return total;
    }
    int pairSum(ListNode* head) {
        int maks = 0;
        int size =  count(head) ;
        stack<int> st;
        st.push(5);
        // return st.top();
        int cnt = 0;
        int i = 0;
        ListNode *first = head;
        ListNode *curr = head;
        while(cnt < size / 2) {
            curr = curr->next;
            cnt++;
        }
        while(curr != NULL) {
            st.push(curr->val);
            curr = curr->next;
        }
        while(i < size / 2) {
            if(first->val + st.top() > maks) {
                maks = first->val + st.top();
                
            }
            st.pop();
            first = first->next;
            i++;
        }

       return maks;

    
    

       
    }
};