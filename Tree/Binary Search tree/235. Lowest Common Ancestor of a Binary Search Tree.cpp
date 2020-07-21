235. Lowest Common Ancestor of a Binary Search Tree
Easy
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]


 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

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
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
 {
        // Value of current node or parent node.
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal) {
            // If both p and q are greater than parent
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            // If both p and q are lesser than parent
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            return root;
        
        }
 }
    
    
    //2. LCA 
//       vector<TreeNode*> nodeToRootPath(TreeNode* node, int data)
//     {
//     if (node == NULL)
//         return {};

//     if (node->val == data)
//     {
//         vector<TreeNode*> base;
//         base.push_back(node);
//         return base;
//     }

//     vector<TreeNode*> left = nodeToRootPath(node->left, data);
//     if (left.size() != 0)
//     {
//         left.push_back(node);
//         return left;
//     }

//     vector<TreeNode*> right = nodeToRootPath(node->right, data);
//     if (right.size() != 0)
//     {
//         right.push_back(node);
//         return right;
//     }

//     return {};
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return LCA_01(root,p->val,q->val);
        
//     }
//     TreeNode *LCA_01(TreeNode *node, int data1, int data2)
//     {
//     vector<TreeNode*> list1 = nodeToRootPath(node, data1);
//     vector<TreeNode*> list2 = nodeToRootPath(node, data2);

//     if (list1.size() == 0 || list2.size() == 0)
//         return {};

//     int i = list1.size() - 1;
//     int j = list2.size() - 1;
//     TreeNode *prev = NULL;

//     while (i >= 0 && j >= 0)
//     {
//         if (list1[i]->val != list2[j]->val)
//             break;

//         prev = list1[i];
//         i--;
//         j--;
//     }

//     return prev;
//     }
    
};
