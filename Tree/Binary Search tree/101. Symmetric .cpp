101. Symmetric Tree
Easy

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
   
   
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
    // 1.Iterative
//     bool isSymmetric(TreeNode* root) {
//         if (root == NULL) return true;
        
//         stack<TreeNode*> st;
//         st.push(root->left);
//         st.push(root->right);
//         while (!st.empty()) {
//             TreeNode* n1 = st.top();
//             st.pop();
//             TreeNode* n2=st.top(); st.pop();
//             if (n1 == NULL && n2 == NULL) continue;
//             if (n1 == NULL || n2 == NULL || n1->val != n2->val) return false;
//             st.push(n1->left);
//             st.push(n2->right);
//             st.push(n1->right);
//             st.push(n2->left);
//     }
//     return true;
//     }
    
    //2.Recursive
    bool isSymmetric(TreeNode* root) {
        return areMirror(root,root);
    }
    
    bool areMirror(TreeNode* a, TreeNode* b) 
    {
        if (a==NULL && b==NULL) 
            return true; 
 
        if (a==NULL || b == NULL) 
            return false; 
  
        if(a->val == b->val)
        {
            return true;
        }
        return  areMirror(a->right, b->left) && areMirror(a->left, b->right);
    }
};
 
