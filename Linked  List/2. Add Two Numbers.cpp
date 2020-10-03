2. Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *c=new ListNode(-1);
        ListNode *anshead=c;  //because every time it will point to NULL so store
        int sum;
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int x,y;
           if(l1!=NULL){
               x=l1->val;
           }
            else{
                x=0;
            }
            if(l2!=NULL){
               y=l2->val;
           }
            else{
                y=0;
            }
            sum=x+y +carry;
            carry=sum/10;
            c->next=new ListNode(sum%10);
            c=c->next;
            
            
            if(l1!=NULL){
                l1=l1->next;
                
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }
        if(carry>0){
            c->next=new ListNode(carry);
        }
            
        
        return anshead->next;
        
        
    }
};
