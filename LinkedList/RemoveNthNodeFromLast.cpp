/* leetcode: 19. Remove Nth Node From End of List

logic:
> Use 2 pointer approach.
> make distance between 2 pointers n , after that move both with same speed till fast reaches to NULL.
> Now important this is to handle cases where are asked to remove head of node.
> So while creating gap of n we only move p2 pointer. If somehow p2 reaches null there means we are asked to remove head of node.
  Because from last with n gap if p2 is null if we crawlfrom last to first we will reach head.

*/

#include <bits/stdc++.h>

ListNode* removeNthFromEnd(ListNode* head, int n) {
        //assuming n is always valid
        if (head == NULL)
            return NULL;
    
        ListNode * p1 = head;
        ListNode * p2 = head;
        
        //here important thing is that we are only moving p2.Now in this while move if p2 reaches NULL it means we have not moved p1 at all
        //hence we are required to remove head of linked list. THis is star thing about this program. e.g. [1,2,3] n=3 means remove 1.
        // assuming n is valid
        while(n--)
            p2 = p2->next;
        
        if(p2 == NULL)
            return head->next;
        
        //if p2 does not reaches last NULL till now means we are not required to remove head of linked list.
        //see significance why p2->next!=NULL conditiion is used not p2!=NULL.
        while(p2->next != NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
        
        //removing nth node from last
        p1->next = p1->next->next;
        return head;
   }
