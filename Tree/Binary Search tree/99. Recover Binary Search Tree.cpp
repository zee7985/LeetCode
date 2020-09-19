99. Recover Binary Search Tree
Hard

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* a=NULL;
    TreeNode* b=NULL;
    //1.
//     void helper(TreeNode* root)
//     {
//         if(root==NULL) return;
//         helper(root->left);
//         if(prev!=NULL && prev->val > root->val)
//         {
//             b=root;
//             if(a==NULL)
//             {
//                 a=prev;
//             }
//             else
//             {
//                 return;  // if a already contain 1 swapped element then no need to continue
//             }
//         }
//         prev=root;     
        
//         helper(root->right);
//     }
    
    void helper(TreeNode* root)
    {
        if(root==NULL) return;
        helper(root->left);
        if(a==NULL && prev!=NULL && prev->val > root->val)  // Assign a to prev-1st swapped ele found
        {
            a=prev;
        }
        if(a!=NULL && prev!=NULL && prev->val > root->val)  // If 1st ele found then only assign root to second
        {
            b=root;
        }
        
        prev=root;     
        
        helper(root->right);
    }
    

    void recoverTree(TreeNode* root) {
        helper(root);
        if(a!=NULL)
        {
            int temp=a->val;
            a->val=b->val;
            b->val=temp;
        }
    }
};
