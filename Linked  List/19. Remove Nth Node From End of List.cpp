19. Remove Nth Node From End of List
Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1

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
    
    //1 .Two pass
//     int length(ListNode *head){
//     int len=0;
//     while(head!=NULL){
//         head=head->next;
//         len++;
//     }
//     return len;
//     }

//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;

//         ListNode *temp=dummy;
//         for(int i=1;i<length(dummy)-n;i++){
//             temp=temp->next;
//         }
//         ListNode *temp1=temp->next;
//         temp->next=temp1->next;
//         delete temp1;
        
//         return dummy->next;
//     }

    //2. one pass
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow=dummy;
        ListNode* fast=dummy;
         
        //Advances first pointer so that the gap between first and second is n nodes apart
        for(int i=0;i<=n;i++)
        {
            fast =fast->next;
        
        }
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
         slow->next=slow->next->next;
        return dummy->next;
     }
    

};
