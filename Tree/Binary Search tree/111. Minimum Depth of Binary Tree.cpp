111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
    //1.
    // int minDepth(TreeNode* node) {
//         if(node == NULL)
//         {
//             return 0;
//         }
        
//         int left=minDepth(node->left);
//         int right= minDepth(node->right);
        
//         if(node->left!=NULL && node->right!=NULL)
//         {
//             return min(left,right)+1;
//         }
//         else{
//             return max(left,right)+1;
//         

    //2.
     int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);      
        
        if(left == 0)
            return right + 1;
        if(right == 0)
            return left + 1;
        
        return min(left,right) + 1;
    }
    
};
