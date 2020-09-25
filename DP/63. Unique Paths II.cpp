63. Unique Paths II
Medium

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

class Solution {
public:
    //1. Recursion + memo
      int numPaths(int i, int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid) {
        
         if(i==m-1 && j==n-1) 
        {
            return obstacleGrid[i][j] == 1 ? 0 : 1; // the edge case, robor is blocked in the top-left corner.

        }
        if (i >=m || j >=n) 
        {
            return 0;
        }
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int count=0;
        if(obstacleGrid[i][j]==1)
        {
            count=0;
        }
        else
        {
            count+=numPaths(i + 1, j,m,n,dp,obstacleGrid);
            count+= numPaths(i, j + 1,m,n,dp,obstacleGrid);
        }
        dp[i][j]=count;
        
        return count;
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return numPaths(0,0,m,n,dp,obstacleGrid);
    }
    
    
    //2.DP
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//         dp[1][0] = 1;
//         //dp[0][1] = 1;
        
//         for (int i = 1; i <=m; i++) {
//             for (int j= 1; j <= n; j++) {
//                if(obstacleGrid[i-1][j-1]==0){
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[m][n];
//     }
};
