968. Binary Tree Cameras
Hard
Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 Example 1:


Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int camera=0;
    public int minCameraCover(TreeNode root) {
        if(minCam(root)==-1){
            camera++;
        }
        return camera;
    }
    
    public int minCam(TreeNode root){
        if(root==null){
            return 0;
        }
       
        //-1  :Need Camera
        // 0  :covered by parent or child
        // 1  :I am camera
        int ls=minCam(root.left);
        int rs=minCam(root.right);
        
        // if(root.left==null && root.right==null){
        //     return -1;
        // }
        
        
        if(ls==-1 || rs==-1){
            camera++;
            return 1;
        }
        else if(ls==1 || rs==1){
            return 0;
        }
        return -1;
    }
}
