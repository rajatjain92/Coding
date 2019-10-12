/*
Problem: Reverse a linked list (leetcode:206)

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
    ListNode* reverseList(ListNode* head) {
        //zero elements
        if(head == NULL)
            return NULL;
        
        //single element
        if(head->next == NULL)
            return head;
        
        ListNode *curr = head;
        
        //p2 and p3 start from same position
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        //here p1 p2 edge will be reversed and p3 will be future node
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
