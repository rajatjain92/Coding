/* Problem: Reverse linked list in groups of k

Logic: Recursively call reverse function for every knodes
*/

/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

//code
struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
        if(head == NULL)
            return NULL;
        
        //single element
        if(head->next == NULL)
            return head;
        
        struct node *p1 = NULL;
        
        //p2 and p3 start from same position
        struct node *p2 = head;
        struct node *p3 = NULL;
        //always start p1,p3 as prev and next from null
        
        int count = 0;
        
        //here p1 p2 edge will be reversed and p3 will be future node
        while(p2 != NULL && count < k){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            count++;
        }
        
        head->next = reverse(p3,k);
        return p1;
}
