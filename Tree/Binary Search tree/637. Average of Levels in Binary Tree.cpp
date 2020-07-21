637. Average of Levels in Binary Tree
Easy

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

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
    vector<double> averageOfLevels(TreeNode* node) {
        vector<double> v;
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
            double sum=0;
            double denominator=size;

            while (size-- > 0)
            {
                TreeNode *currNode = que.front();
                que.pop();
                //ans.push_back(currNode->val);
                sum+=currNode->val;

                if (currNode->left != NULL)
                {
                    que.push(currNode->left);
                }

                if (currNode->right != NULL)
                {
                    que.push(currNode->right);
                }
            }
            sum=(sum/denominator);
            v.push_back(sum);
        }
        return v;
        
    }
};
