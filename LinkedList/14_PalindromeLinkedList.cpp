/* Problem : 234. Palindrome Linked List

T.C. O(n)
S.C. O(1) No extra auxiliary space

You are not allowed to modify linked list
In the solution below O(n) stack space is used for recursion.

For O(1) space reverse the half part of linked list and then check element by element. 
But in that approach we would be modifying linked list.

IMPORTANT:
one thing which we can notice is that we have to pass pointer to a pointer for left part.
Why can't we make rec like rec(ListNode *left,ListNode *right){} So question is why do we pass pointer to pointer.

So the answer is for right we are sending updated value to next recursion by sending right->next. But we also need
to update left but we are doing it with recursion so :
 to update pointer through recursion you need to use double pointer . Refer article :
 " https://stackoverflow.com/questions/25945604/double-pointer-in-recursion-is-required "
 So learning is use to update value of variable use single pointer but to update single pointer you need to use 
 double pointer.
 
 A "double pointer" is required because you're changing the value of the pointer within the function.

Without even looking at your code, look at this very simple example:

void foo(int *x)
{
   x = new int[10];
}

int main()
{
   int *p = 0;
   foo(p);
   // why is p still NULL?
}
You will see that the value of p didn't change, even though the function obviously changes the parameter that was passed. 
The problem is that x is a temporary variable, and any changes to x go away once the function exits.

To fix this problem, you must either pass a pointer to the pointer, or a reference to the pointer:

void foo(int** x)
{
    *x = new int[10];
}

void foo2(int *& x)
{
    x = new int[10];
}

int main()
{
    int *p = 0;
    foo(&p);  // now p will change
    delete [] p;

    p = 0;  // try again
    foo2( p );  // p also changes here
    delete [] p;
}

Read more from article in given link.
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
