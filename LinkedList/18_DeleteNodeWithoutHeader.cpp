/* leetcode problem : 237. Delete Node in a Linked List
you are only given access to node you want to delete.

logic:
> update val of next node in node to be deleted and then bypass next node. So basically we are copying next node to delete node
  and then bypass next node. So delete node will be connected to next to next.
*/

#include <bits/stdc++.h>

void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
