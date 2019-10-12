/* Problem : Sort a linked list of all 0's , 1's and 2's
*/

/*
> First approach:
> Traverse the whole linked list to count number of 0's 1's and 2's 
> Then fill the linked list with these values
> T.C O(n) S.C. O(1)
*/

#include <bits/stdc++.h>

void Sort_list(ListNode * head){
  int arr[3] = {0};
  ListNode * ptr = head;
  
  while (ptr != NULL){
    arr[ptr->val] += 1;
    ptr = ptr->next;
  }
  
  ptr = head;
  int index = 0;
  
  while (ptr != NULL){
    if(arr[index] == 0)
      i++;
    else{
     ptr->val = i;
     arr[i]--;
     ptr = ptr->next;
    }
  }
}


/* Second Approach:
> This approach should be used where you cannot modify linked list.
> Make 3 different lists for 0,1,2 and then combine them
> Also take care of cases when 1 is not present or 2 or 0 or both etc.
*/

Node* segregate(Node *head) {
    
    // Add code here
    Node * zero = new Node(0);
    Node * one  = new Node(0);
    Node * two  = new Node(0);
    
    Node * p0 = zero;
    Node * p1 = one;
    Node * p2 = two;
    
    Node * curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            p0->next = curr;
            p0 = p0->next;
            curr = curr->next;
        }
        else if(curr->data == 1){
            p1->next = curr;
            p1 = p1->next;
            curr = curr->next;
        }else{
            p2->next = curr;
            p2 = p2->next;
            curr = curr->next;
        }
    }
    
    p0->next = one->next ? one->next : two->next;
    p1->next = two->next;
    p2->next = NULL;
    
    head = zero->next;
    delete(zero);
    delete(one);
    delete(two);
    
    return head;
}

     
