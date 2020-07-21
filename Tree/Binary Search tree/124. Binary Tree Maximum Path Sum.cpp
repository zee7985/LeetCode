124. Binary Tree Maximum Path Sum
Hard
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxSum=(int) -1e7;
    int nodeToNodeMaxSum(TreeNode* node) {
        if (node == NULL)
            return 0;

        int leftsum = nodeToNodeMaxSum(node->left);
        int rightsum = nodeToNodeMaxSum(node->right);
        
        int sideMax = max(leftsum, rightsum) + node->val;
        maxSum = max(max(maxSum, sideMax), max(leftsum + rightsum + node->val, node->val));

        return max(sideMax, node->val);
    }
    int maxPathSum(TreeNode* root) {
         nodeToNodeMaxSum(root);
        return maxSum;
        
    }
};
