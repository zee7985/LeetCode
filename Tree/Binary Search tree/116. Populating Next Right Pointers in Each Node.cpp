116. Populating Next Right Pointers in Each Node
Medium

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //O(n) space
//     Node* connect(Node* root) {
//         if(root==NULL){
//             return NULL;
//         }
//         queue<Node*> q;
//         q.push(root);
        
//         while(!q.empty()){
//             int size = q.size();
//             Node *prev = NULL;
//             for(int i=0;i<size;i++){
                
//                 Node *curr = q.front();
//                 q.pop();
                
//                 if(prev!=NULL){
//                     prev->next = curr;
//                 }
//                 if(curr->left) q.push(curr->left);
//                 if(curr->right) q.push(curr->right);
//                 prev = curr;
//             }           
            
//         }
//         return root;
//     }
    
    //O(n) with O(1) space
    //Use the property of full binary tree
    Node* connect(Node *root) {
        if(root==NULL) return NULL;
        Node*temp=root;
        while(temp->left)
        {
            Node *p = temp;
            while(p)
            {
                p->left->next =p->right;
                if(p -> next)
                {
                    p->right->next = p->next->left;
                }
                p = p -> next;
            }
            temp = temp->left;
        }
        return root;
    }
    
};
