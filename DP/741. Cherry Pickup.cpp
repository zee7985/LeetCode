741. Cherry Pickup
Hard


You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

Example 1:


Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
Example 2:

Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
grid[i][j] is -1, 0, or 1.
grid[0][0] != -1
grid[n - 1][n - 1] != -1
  

// Instead of having two paths starting from 0,0 and then other path from N,N. 
// We can have two people starting from 0,0 and find two paths that collects maximum cherries.
// First  person finds the path to collect maximum cherries and mark those cherries collected then
// Second person finds another path to collect maximum cherries. 

// So we have four state r1,c1,r2,c2 ,then dp[r1][c1][r2][c2] will identify each state. ,But time complexity
// will be O(N^4)
// But it can be converted into O(N^3) by observing that at a time r1+c1=r2+c2  as a person will move only 1 step towards dest
// then we can find r2 using this equation r2=r1 + c1- c2

// Thus we have 3 unique states now and  dp[r1][c1][c2] will identify each state.


class Solution {
public:
    int dp[50][50][50];
    int helper(int r1,int c1,int c2,int n,vector<vector<int>> &grid)
    {
        int r2= r1+ c1 - c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];

        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        
        
        int ans=grid[r1][c1];
        if(c1!=c2) ans+=grid[r2][c2];  //if both persons standing on the same cell, don't double count and return what's in this cell (r1,c1) otherwise add  cell(r2,c2)
        
        // since each person of the 2 person can move only to the bottom or to the right, then the total number of cherries
        // equals the max of the following possibilities:
        //    P1     |      P2
        //   DOWN    |     DOWN
        //   DOWN    |     RIGHT
        //   RIGHT   |     DOWN
        //   RIGHT   |     RIGHT
        int temp=max(helper(r1,c1+1,c2+1,n,grid),max(helper(r1,c1+1,c2,n,grid),max(helper(r1+1,c1,c2+1,n,grid),helper(r1+1,c1,c2,n,grid))));
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,helper(0,0,0,n,grid));    // Return 0 if ans equals to INT_MIN
    }
};
