92. Reverse Linked List II
Medium

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     //here we will  use 4 pointer to reverse the sublist and reduce our problem to only insertion and deletion   
    ListNode* reverseBetween(ListNode* head, int s, int e) {
        if(!head || s==e)
        {
            return head;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode *nodeBeforeSublist=&dummy; // make a pointer as a marker for the node before reversing 
                                            // eg -1->2->3->4->5->6   m=3,n=5
                                            //nodeBeforeSublist will point at 2
                                                
        int count=1;
        
        while(count<s)
        {
            nodeBeforeSublist=nodeBeforeSublist->next;
            count++;
        }
        
        ListNode* workingPtr=nodeBeforeSublist->next; // a pointer to the begin of sub-list(i.e Node 3) that will be reversed 

        while(s<e)  
        {
            ListNode* nodeToBeExtracted=workingPtr->next; // a pointer to a node that will be reversed-actually we                                                                                           //start reversing from 2nd node of sublist (i.e node 4)
            
            workingPtr->next=nodeToBeExtracted->next;   //make node 3 point to node 5
            
            nodeToBeExtracted->next=nodeBeforeSublist->next;   // node 4 point to start of sublist i.e node 3
            nodeBeforeSublist->next=nodeToBeExtracted;         // and then  node 2 point to node 4;
            s++;
            
        }
        
        // first reversing : dummy->1->2->4->3->5->6  ,nodeBeforeSublist = 2,workingPtr=3,nodeToBeExtract=5
        // second reversing: dummy->1->2->5->4->3->6  ,nodeBeforeSublist = 2,s<=e  ->finish
        return dummy.next;
        
    }
};
