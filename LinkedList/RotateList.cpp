/* leetocde (61)
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

#include <bitsstdc++.h>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        int len = 1;
        ListNode * p = head;
        
        while(p->next){
            len++;
            p = p->next;
        }
        
        //join last element to first element
        p->next = head;
        
        //k can be > n
        if(k >= len)
            k = k % len;
        
        ListNode * p2 = head;
        ListNode * p3 = head;
        
        //new position of last element
        int tmp = len-k-1;
        
        while(tmp){
            p2 = p2->next;
            tmp--;
        }
        
        //new start position
        p3 = p2->next;
        //create last element
        p2->next = NULL;
        
        return p3;
    }
};
