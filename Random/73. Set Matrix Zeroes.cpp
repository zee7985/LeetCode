73. Set Matrix Zeroes
Medium

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


class Solution {
public:
    //1. O(mn) with o(m+n)space
//     void setZeroes(vector<vector<int>>& matrix) {
//         set<pair<int,int>> s;
        
        
//         for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[0].size();j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     s.insert({i,j});
//                 }
//             }
//         }
        
//         for(auto a: s)
//         {
//             int i=a.first;
//             int j=a.second;
            
//             for(int k=0;k<matrix[0].size();k++)
//             {
//                 matrix[i][k]=0;
//             }
//             for(int k=0;k<matrix.size();k++)
//             {
//                 matrix[k][j]=0;
//             }
//         }
        
//     }
    
    //2.o(mn) with o(1) space
    // store states of each row in the first of that row, and store states of each column in the first
    //of that column. Because the state of row0 and the state of column0 would occupy the same cell,
    //I let it be the state of row0, and use another variable "col0" for column0.
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
    }
};
