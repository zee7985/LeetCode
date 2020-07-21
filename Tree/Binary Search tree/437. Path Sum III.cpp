437. Path Sum III
Easy

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

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


// So the idea is similar as Two sum, using HashMap to store ( key : the prefix sum, value : how many ways get
// to this prefix sum) , and whenever reach a node, we check if prefix sum - target exists in hashmap or not, 
// if it does, we added up the ways of prefix sum - target into res.
// For instance : in one path we have 1,2,-1,-1,2, then the prefix sum will be: 1, 3, 2, 1, 3,
// let's say we want to find target sum is 2, then we will have{2}, {1,2,-1}, {2,-1,-1,2} and {2}ways.
    
class Solution {
public:
     int ans=0;
    void pathSumIII(TreeNode* node, int tar, int prefixSum, map<int,int> mp) {
        if (node == NULL)
            return;

        prefixSum += node->val;

        if(mp.find(prefixSum - tar)!=mp.end())
        {
            ans+=mp[prefixSum - tar];
        }
        mp[prefixSum]++;

        pathSumIII(node->left, tar, prefixSum, mp);
        pathSumIII(node->right, tar, prefixSum, mp);

        mp[prefixSum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        map<int,int> mp;
        mp[0]++;
        
        pathSumIII(root,sum, 0,mp );
        return ans;
        
    }
};


