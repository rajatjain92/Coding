/* leetcode - 141
Detect cycle in linked list

T.C. - O(n)
S.C. - O(1)

Ques> How to prove there will be intersection btw slow and fast pointer in linked list???
Ans>  If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.

      Now consider a cyclic list and imagine the slow and fast pointers are two runners racing around a circle track. 
      The fast runner will eventually meet the slow runner. Why? Consider this case (we name it case A) - The fast runner is just one 
      step behind the slow runner. In the next iteration, they both increment one and two steps respectively and meet each other.

      How about other cases? For example, we have not considered cases where the fast runner is two or three steps behind the slow 
      runner yet.This is simple, because in the next or next's next iteration, this case will be reduced to case A mentioned above.

Ques> How to prove time complexity is O(n)???
      https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/ (refer this link)
Ans>  > If there is no cycle: then p2 will be null first hence O(N) time.
      > If there is a cycle: 
            1) When slow pointer enters the loop, the fast pointer must be inside the loop. 
               Let fast pointer be distance k from slow.

            2) Now if consider movements of slow and fast pointers, we can notice that distance between them (from slow to fast) 
               increase by one after every iteration. After one iteration (of slow = next of slow and fast = next of next of fast), 
               distance between slow and fast becomes k+1, after two iterations, k+2, and so on. When distance becomes n, they meet 
               because they are moving in a cycle of length n. So we will meet in n-k iterations hence O(n).


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
