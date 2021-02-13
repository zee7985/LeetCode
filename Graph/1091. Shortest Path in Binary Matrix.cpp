1091. Shortest Path in Binary Matrix
Medium

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:
Input: [[0,1],[1,0]]
Output: 2

Example 2:
Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        queue<pair<int,int>> que;
        

        que.push({0,0});
        grid[0][0]=1;
        int step=1;
        
        while(!que.empty())
        {
            int size=que.size();
            while(size-->0)
            {
                auto curr=que.front(); que.pop();
                int x_=curr.first;
                int y_=curr.second;
                
                
                if(x_== n-1 && y_==n-1) return step;
                
                for(auto direction : directions){
                    int x = x_ + direction[0];
                    int y = y_ + direction[1];
                    
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0)
                    {
                        
                        que.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
            step++;
            
        }

        return -1;
    }
    
    
    //81/84 Testcases passed -It is not a DP prob because DP doesn't work because we  will not calculate all 8       paths before calculating a path. Let see 1,1 now all the 8 paths are valid but not all 8 paths are available     to you. That's the difference between this and other DP problems.
//         int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n=grid.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX-1));
        
        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(j==1 && i==1  && grid[0][0]==0)
//                 {
//                     dp[i][j]=1;
//                     continue;
//                 }
                    
//                 if(grid[i-1][j-1]==0)
//                 {
//                     dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
//                 }
//             }
//         }
//         return dp[n][n]==INT_MAX ? -1 : dp[n][n];
//     }
        
        
};
