113. Path Sum II
Medium

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int sum,vector<int> c)
    {
         if(root==NULL)
        {
            return;
        }
        
         if(sum==root->val && root->left==NULL  && root->right==NULL)   //Check if it is a leaf
        {
            c.push_back(root->val);
             ans.push_back(c);
             //c.pop_back();             // pass by value and not reference ,then no need of pop_back
        }
        
        c.push_back(root->val);
        helper(root->left,sum-root->val,c);
        helper(root->right,sum-root->val,c);
        //c.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> c;
         if(root==NULL)
        {
            return {};
        }
        helper(root,sum,c);
        return ans;
       
    }
    
};
