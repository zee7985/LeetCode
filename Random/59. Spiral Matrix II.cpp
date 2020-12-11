59. Spiral Matrix II
Medium

1433

125

Add to List

Share
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 1));
        int left, right, top, bottom, val=0;
        left = top = 0, right = bottom = n-1;
        
        while (val<n*n) 
        {
            for ( int j = left; j <= right; j++)
                res[top][j] = ++val;
            top++;
            for (int i = top; i <= bottom; i++)
                res[i][right] = ++val;
            right--;
            for (int j = right; j >= left; j--)
                res[bottom][j] = ++val;
            bottom--;
            for (int i = bottom; i >= top; i--)
                res[i][left] = ++val;
            left++;
        }
        return res;
    }
};
