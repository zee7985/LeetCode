897. Increasing Order Search Tree
Easy

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 Example 1:
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:
Input: root = [5,1,7]
Output: [1,null,5,null,7]

Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8

 
Constraints:
The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
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
    //O(n) with O(H) space-H:Height of tree
    //Inorder Traversal 
    void inorder(TreeNode* root,TreeNode* &ans)
    {
        if(root==NULL) return;
        inorder(root->left,ans);            // Go to leftmost element 
        ans->right=new TreeNode(root->val); // add to the right of our ans
        ans=ans->right;
        inorder(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode*temp;
        TreeNode*ans=new TreeNode();
        temp=ans;
        inorder(root,ans);
        return temp->right;
    }
};
