237.Delete Node in a Linked List
Easy
Solution
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:



 Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.


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
       // The idea behind this solution is we have only access to node to be deleted.
       //  So, copy the contents of next node and delete the next node.
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;    
        
    }
};