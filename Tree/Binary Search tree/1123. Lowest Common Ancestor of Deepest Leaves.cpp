1123. Lowest Common Ancestor of Deepest Leaves
Medium

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
Note: This question is the same as 865: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

 
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

Constraints:

The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.


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
    //Solution:
    // If left subtree height is greater, then the result is whatever returned by the left as it has highest depth elements.
    // Similarly if right subtree height is greater, then the result is whatever returned by the right as it has highest depth elements.
    // If heights of both left and right subtrees are equal then the current node is the common ancestors of the deepest leaves.
    
    //O(n) complexity
    
    map<TreeNode*,int> mp;  //Using map to store the depth of each node so that we donot need to calculate everytime
                            //This makes complexity O(n) from O(n^2) but also increases the extra space
    int depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        if(mp.find(root)!=mp.end()) return mp[root];
        
        int left=depth(root->left);
        int right=depth(root->right);
        int maxDepth=max(left,right)+1;
        mp[root]=maxDepth;
        
        return maxDepth;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        
        int leftD=depth(root->left);
        int rightD=depth(root->right);
        
        if(leftD==rightD)
        {
            return root;
        }
        else if(leftD > rightD)
        {
            return lcaDeepestLeaves(root->left);
        }
        else if(leftD < rightD)
        {
            return lcaDeepestLeaves(root->right);
        }
        return NULL;
    }
};
