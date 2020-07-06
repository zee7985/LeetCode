1008. Construct Binary Search Tree from Preorder Traversal
Medium

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]


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

// In the solution above, we are searching for a split point to divide the interval. Instead, we can pass the parent value 
to the recursive function to generate the left sub-tree. The generation will stop when the value in the preorder array 
exceeds the parent value. That will be our split point to start generating the right subtree.

class Solution {
public:
    int idx=0;
    TreeNode* bstFromPreorder(vector<int>& arr,int parent=INT_MAX) {
         if (idx >= arr.size() || arr[idx] >parent)
        {
            return NULL;
        }

        TreeNode *node = new TreeNode(arr[idx]);
        idx++;

        node->left = bstFromPreorder(arr,node->val);
        node->right = bstFromPreorder(arr,parent);
        return node;
       
        
    }
};
