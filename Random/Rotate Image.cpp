48. Rotate Image
Medium

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        reverse(matrix.begin(), matrix.end());   //for clockwise
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        //reverse(matrix.begin(), matrix.end());  //for anticlockwise


        
    }
};

Clockwise
1 2 3   reverse    7 8 9  transpose   7 4 1
4 5 6  --------->  4 5 6 ---------->  8 5 2
7 8 9              1 2 3              9 6 3

Anticlockwise
1 2 3   transpose  1 4 7 reverse      3 6 9
4 5 6  --------->  2 5 8 ---------->  2 5 8
7 8 9              3 6 9              1 4 7
