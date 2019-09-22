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
        
        ListNode *p1 = head;
        
        //p2 and p3 start from same position
        ListNode *p2 = p1->next;
        ListNode *p3 = p1->next;
        
        //ready you new tail
        p1->next = NULL;
        
        //here p1 p2 edge will be reversed and p3 will be future node
        while(p3 != NULL){
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};
