/* leetcode - 141
Detect cycle in linked list

T.C. - O(n)
S.C. - O(1)

Ques> How to prove there will be intersection btw slow and fast pointer in linked list???
If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.

Now consider a cyclic list and imagine the slow and fast pointers are two runners racing around a circle track. 
The fast runner will eventually meet the slow runner. Why? Consider this case (we name it case A) - The fast runner is just one 
step behind the slow runner. In the next iteration, they both increment one and two steps respectively and meet each other.

How about other cases? For example, we have not considered cases where the fast runner is two or three steps behind the slow runner yet. 
This is simple, because in the next or next's next iteration, this case will be reduced to case A mentioned above.

Ques> How to prove time complexity is O(n)???
Complexity analysis

Time complexity : O(n)O(n). Let us denote nn as the total number of nodes in the linked list. To analyze its time complexity, 
we consider the following two cases separately.

List has no cycle:
The fast pointer reaches the end first and the run time depends on the list's length, which is O(n)O(n).

List has a cycle:
We break down the movement of the slow pointer into two steps, the non-cyclic part and the cyclic part:

The slow pointer takes "non-cyclic length" steps to enter the cycle. At this point, the fast pointer has already reached the cycle.
\text{Number of iterations} = \text{non-cyclic length} = NNumber of iterations=non-cyclic length=N

Both pointers are now in the cycle. Consider two runners running in a cycle - the fast runner moves 2 steps while the slow runner 
moves 1 steps at a time. Since the speed difference is 1, it takes
\dfrac{\text{distance between the 2 runners}}{\text{difference of speed}} 
difference of speed
distance between the 2 runners
​	
  loops for the fast runner to catch up with the slow runner. As the distance is at most "\text{cyclic length K}cyclic length K" and 
  the speed difference is 1, we conclude that
\text{Number of iterations} = \text{almost}Number of iterations=almost "\text{cyclic length K}cyclic length K".

Therefore, the worst case time complexity is O(N+K)O(N+K), which is O(n)O(n).

Space complexity : O(1)O(1). We only use two nodes (slow and fast) so the space complexity is O(1)O(1).
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        //if there is no cycle p2 will reach end first
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
                return true;
        }
        return false;
    }
};
