199. Binary Tree Right Side View
Medium

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

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
    vector<int> rightSideView(TreeNode* node) {
        vector<int> v;
        if(node==NULL)
        {
            return {};
        }
        
        queue<TreeNode*> que;
        que.push(node);

        while (que.size() != 0)
        {
            int size = que.size();
            int prev=0;
            while (size-- > 0)
            {
                TreeNode *currNode = que.front();
                que.pop();
                //ans.push_back(currNode->val);
                prev=currNode->val;

                if (currNode->left != NULL)
                {
                    que.push(currNode->left);
                }

                if (currNode->right != NULL)
                {
                    que.push(currNode->right);
                }
            }
            v.push_back(prev);

        }
        return v;
        
    }
    
};
