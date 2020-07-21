894. All Possible Full Binary Trees
Medium
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Explanation:

 /**
Okay, so first thing to note here is that for complete binary tree to happen, we can only have odd number of nodes possible, i.e., 1,3,5,7,... and so on. And whenever I take one node from the total nodes to create a root node, I will be left will even number of nodes. But again, for binary tree to happen, we need odd number of nodes for both the left as well as right subtrees. So To have that, we will do:
Decrease the value of N by 1 and then take all possible odd, odd combinations from the N-1 value. E.g., N=7, one node will be taken away for root node, then for remaining 6 nodes, I will divide them as (1,5),(3,3),(5,1). And now follow the same procedure for its left and right childrens. Then we can take all possible combinations in (A*B) ways where A is the number of ways we can create left subtree and B is the number of ways we can create right subtree.

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
    
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        if(N==1) return vector<TreeNode*>{new TreeNode(0)};
        //--N;
        
        vector<TreeNode*> res;
        
        for(int i=1;i<N;i+=2)// i+=2 because i should always be odd number. When 3 is 1 this main                                   loop executes only once.

        {
            vector<TreeNode*> x = allPossibleFBT(i);  // list of all possible left subtrees
            vector<TreeNode*> y = allPossibleFBT(N-i-1);// list of all possible right subtrees
            for(int j=0;j<x.size();j++){        // for loop because we want all the combination
                for(int k=0;k<y.size();k++){
                    TreeNode* root = new TreeNode(0);// Create a parent node and assign the left 
                                            //and right subtrees to this and add it to the vector
                    root->left  = x[j];
                    root->right = y[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
