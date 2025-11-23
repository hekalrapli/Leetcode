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
        int total = 0;
        while(p != NULL) {
            total++;
            p = p->next;
        }
        return total;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *x = head;
        ListNode *l = NULL;
        ListNode *r = NULL;
        ListNode* pre_l = NULL;
        ListNode* pre_r = NULL;
        int size = len(x);
        int cnt = 1;
        while(temp != NULL) {
            if(cnt == k) {
                l = temp;
            }
            if(cnt == size-k+1) {
                r = temp;
            }
            if(cnt < k) {
                pre_l = temp;
            }
            if(cnt < size-k+1) {
                pre_r = temp;
            }
            cnt++;
            temp = temp->next;
        }
    //    return pre_l;
        if(pre_l != NULL && pre_r != NULL && pre_l == r ) {
            ListNode *curr = l->next;
            pre_r ->next = l;
            l->next = r;
            r->next = curr;

        }
        else if(pre_l != NULL && pre_r == l) {
            ListNode * curr = r->next;
            pre_l -> next = r;
            r->next = l;
            l->next = curr;
        
        }
        else if(pre_l != NULL && pre_r != NULL) {
        ListNode *curr = r->next;
        pre_l ->next = r;
        r->next = l->next;
        pre_r->next = l;
        l->next = curr;
        }
        else if(pre_l == NULL && pre_r == l && pre_r != NULL) {
            ListNode *curr = r->next;
            r->next = l;
            l->next = curr;
             return r;
        }
        else if(pre_l == NULL && pre_r != l && pre_r != NULL) {
            ListNode *curr = r->next;
            r->next = l->next;
            l->next = curr;
            pre_r ->next = l;
             return r;

        }else if(pre_l != NULL && pre_r == NULL && pre_l == r) {
            ListNode *curr = r->next;
            ListNode *curr2 = l->next;
            l->next = r;
            r->next = curr2;
            return l;
        }else if(pre_l != NULL && pre_r == NULL) {
            ListNode *curr = r->next;
            ListNode *curr2 = l->next;
            l->next = curr;
            pre_l->next = r;
            r->next = curr2;
            return l;
        }
        return head;
    }
};