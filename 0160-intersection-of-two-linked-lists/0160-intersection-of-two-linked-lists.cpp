/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *Temp_a;
        ListNode *Temp_b;
        Temp_a = headA;
        while(Temp_a != NULL ) {
            Temp_b = headB;
            while(Temp_b != NULL) {
                if(Temp_a == Temp_b) {
                    return Temp_a;
                }else {
                    Temp_b = Temp_b -> next;
                }
            }
            Temp_a = Temp_a -> next;
        }
        return Temp_a;
        
    }
};