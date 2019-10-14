/* Problem : 234. Palindrome Linked List

T.C. O(n)
S.C. O(1) No extra auxiliary space

You are not allowed to modify linked list
In the solution below O(n) stack space is used for recursion.

For O(1) space reverse the half part of linked list and then check element by element. 
But in that approach we would be modifying linked list.

*/

#include <bits/stdc++.h>

bool rec(ListNode ** left,ListNode * right){
    //We are moving right pointer means eventually it will reach end of linked list
    if(right == NULL)
        return true;
    
    // move the right pointer to last of the linked list
    if(!rec(left,right->next))
        return false;
    
    //check the value
    bool ans = ((*left)->val == right->val);
    
    //move the left pointer
    *left = (*left)->next;
    return ans;
}
    
bool isPalindrome(ListNode* head) {
    return rec(&head,head);
}
