/* Problem : Remove loop from linked list

refer https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
for diagram 
Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time

From above equation, we can conclude below

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 

So m = O(n-1) + n - k   ,So O(n-1) is fast pointer revolving around circle, So slow pointer will move m while fast pointer will move
n-k. Hence they move at starting point. So trick is use floyd approach of slow pointer and fast pointer. Both pointers meet k length 
in cycle . Now move slow pointer back to start. Now move both slow and fast at same speed. They will meet at starting points of cycle.


*/

#include <bits/stdc++.h>

ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            //cycle found
            if(slow == fast){
                //move slow pointer again to starting point
                slow = head;
                
                //now move slow and fast at same speed they will meet at starting point
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                //this return sholud be here to break while loop e.g [1,2] loop to 1
                return slow;
            }
        }
        return NULL;
    }
