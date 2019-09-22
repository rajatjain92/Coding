/* Problem : Middle element in linked list (leetcode:876)
We dont have to find size otherwise we will waste one loop there.
try to visualise where slow pointer and fast pointer will land in case of odd and even. always take carre of corner cases
when list is empty or with just 1 element.

T.C. O(N)
*/


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
    ListNode* middleNode(ListNode* head) {
        if(head  == NULL)
            return NULL;
        
        //slow pointer
        ListNode * p1 = head;
        //fast pointer
        ListNode * p2 = head;
        
        //p2 needs to take 2 jumps so check both next
        while(p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        //if size of linked list is odd ptr2 will end on last node and ptr1 will be in middle position
        // but if size is even ptr2 will end up on second last node and we need to still need to increase prt1 by 1
        if(p2->next != NULL)
            p1 = p1->next;
        
        return p1;
    }
};
