107. Binary Tree Level Order Traversal II
Easy

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
            

    vector<vector<int>> levelOrderBottom(TreeNode* node) {
        vector<vector<int>> v;
        if(node==NULL)
        {
            return {};
        }
        
        queue<TreeNode*> que;
        que.push(node);

        //int level = 0;
        while (que.size() != 0)
        {
            int size = que.size();
            //cout << "Level: " << level << " -> ";
            vector<int> ans;

            while (size-- > 0)
            {
                TreeNode *currNode = que.front();
                que.pop();
                

                //cout << currNode->data << ", ";
                ans.push_back(currNode->val);

                if (currNode->left != NULL)
                {
                    que.push(currNode->left);
                }

                if (currNode->right != NULL)
                {
                    que.push(currNode->right);
                }
            }
            v.push_back(ans);

        //level++;
        //cout << "\n";
        }
    //cout << "\n";
        return vector(v.rbegin(),v.rend());
        
    }
};
