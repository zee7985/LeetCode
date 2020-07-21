993. Cousins in Binary Tree
Easy

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

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
    bool isCousins(TreeNode* root, int x, int y) {
    
        // Adding each node along with its parent node in the queue and applying BFS
        
        // current and its parent
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, root});

        while (!q.empty())
        {
            int size = q.size();
            bool f = false;
            TreeNode* parent;

            while(size-->0)
            {
                auto cur = q.front();
                TreeNode* node = cur.first;
                TreeNode* its_parent = cur.second;

                if (node->val == x || node->val == y)
                {
                    if (f) {
                        if (its_parent != parent) return true;
                        else return false;
                    }

                    f = true;
                    parent = its_parent;
                }

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});

                q.pop();

            }

            if (f) return false;
        }

        return false;

    }
};
