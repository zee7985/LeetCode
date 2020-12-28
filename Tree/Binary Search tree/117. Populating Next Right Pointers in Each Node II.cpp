117. Populating Next Right Pointers in Each Node II
Medium

Given a binary tree

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

Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100

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
    // O(N) space -BFS
      Node* connect(Node* root) {
         if (root==NULL) return NULL;
        queue<Node*> q;
        q.push (root);
        q.push(NULL);
       
   
    
        while(!q.empty())
        {
          Node* current=q.front();
                 q.pop();
              if(!current && !q.empty()) q.push(NULL);
              if(current && current->left !=NULL)   q.push(current->left);
              if(current && current->right!=NULL)  q.push(current->right);
              if(current && !q.empty()) current->next=q.front();
            }
          return root;  
  
    }
    
    //O(2n) with O(1) space (Each Node will be visited twice)
    Node* connect(Node *root) {
        if(root==NULL) return NULL;
        
        Node *p = root;
        while(p!=NULL)
        {
            Node*curr=NULL;
            Node*nlh=NULL;   // First node of the next level-so that we can strt next level iteration from here
            
            while(p!=NULL)
            {
                if(p->left!=NULL)
                {
                    if(curr==NULL)          // First node of the level
                    {
                        curr=nlh=p->left;
                    }
                    curr->next=p->left;
                    curr=p->left;
                }
                if(p->right!=NULL)
                {
                    if(curr==NULL)          // First node of the level
                    {
                        curr=nlh=p->right;
                    }
                    curr->next=p->right;
                    curr=p->right;
                }
                p=p->next;
            }
            if(curr)
            {
                curr->next=NULL;  // this will be pointing to last node of previous level so disconnect
            }
            p=nlh;
        }
        return root;
    }
};
