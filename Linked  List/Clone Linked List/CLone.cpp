An intuitive solution is to keep a hash table for each node in the list, via which we just need 
to iterate the list in 2 rounds respectively to create nodes and assign the values for their random
 pointers. As a result, the space complexity of this solution is O(N), although with a linear time
 complexity.

Note: if we do not consider the space reversed for the output, then we could say that the algorithm
 does not consume any additional memory during the processing, i.e. O(1) space complexity

As an optimised solution, we could reduce the space complexity into constant. The idea is to
 associate the original node with its copy node in a single linked list. In this way, we don't
 need extra space to keep track of the new nodes.

The algorithm is composed of the follow three steps which are also 3 iteration rounds.

Iterate the original list and duplicate each node. The duplicate
of each node follows its original immediately.
Iterate the new list and assign the random pointer for each
duplicated node.
Restore the original list and extract the duplicated nodes.

138. Copy List with Random Pointer
Medium

3883

723

Add to List

Share
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //1.map two solution-o(n) space
    // Node* copyRandomList(Node* head) {
    //     if (head==NULL) return NULL;
    //     map<Node*,Node*> mp;
    //     Node* ptr1=new Node(head->val);
    //     Node* newHead=ptr1;
    //     mp[head]=ptr1;
    //     Node* ptr=head;
    //     while(ptr!=NULL)
    //     {
    //         Node *randomNode=ptr->random;
    //         Node *nextNode=ptr->next;
    //         if(randomNode!=NULL)
    //         {
    //             if(mp.find(randomNode)==mp.end())
    //             {
    //                 mp[randomNode]=new Node(randomNode->val);
    //             }
    //         }
    //         ptr1->random=mp[randomNode];
    //         if(nextNode!=NULL)
    //         {
    //             if(mp.find(nextNode)==mp.end())
    //             {
    //                 mp[nextNode]=new Node(nextNode->val);
    //             }
    //         }
    //         ptr1->next=mp[nextNode];
    //         ptr1=ptr1->next;
    //         ptr=ptr->next;
    //     }
    //     return newHead;
    // }
    
    //2.Map solution 
    // First make copy of all the nodes and store in map
    // and  then link it with random and next
// 	Node* copyRandomList(Node* head) {
// 		if(head==NULL) return head;
        
        
// 		Node* cur = head;
// 		map<Node*, Node*> mp;
// 		while(cur){
// 			Node* temp = new Node(cur->val);
// 			mp[cur] = temp;
// 			cur = cur->next;
// 		}
// 		cur = head;
// 		while(cur){
// 			mp[cur]->next = mp[cur->next];
// 			mp[cur]->random = mp[cur->random];
// 			cur = cur->next;
// 		}
// 		return mp[head];
// 	}
    
    
    //3. Without Map though it is taking o(n) space but it is considered auxillary space ,so o(1)
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL; 
        Node* c=head;
        while(c!=NULL)
        {
            Node* nextNode=c->next;
            c->next=new Node(c->val);
            
            c->next->next=nextNode;
            c=nextNode;
        }
        
        c=head;
        while(c!=NULL)
        {
            if(c->random!=NULL)
            {
                c->next->random=c->random->next;
            }
            c=c->next->next;
        }
        
        c=head;
        Node* copy=head->next;
        Node* deepCopy=copy;
        
        while(deepCopy->next!=NULL)
        {
            c->next=c->next->next;
            c=c->next;
            
            deepCopy->next=deepCopy->next->next;
            deepCopy=deepCopy->next;
        }
        c->next=c->next->next;
        return copy;
    }
};