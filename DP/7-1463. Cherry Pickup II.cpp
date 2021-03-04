1463. Cherry Pickup II
Hard


Given a rows x cols matrix grid representing a field of cherries. Each cell in grid represents the number of cherries that you can collect.

You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

Return the maximum number of cherries collection using both robots  by following the rules below:

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
When any robot is passing through a cell, It picks it up all cherries, and the cell becomes an empty cell (0).
When both robots stay on the same cell, only one of them takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in the grid.
 

Example 1:



Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.
Example 2:



Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.
Example 3:

Input: grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
Output: 22
Example 4:

Input: grid = [[1,1],[1,1]]
Output: 4
 

Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100 

//  We can't move robot1 firstly to the bottom row, and then move robot2 because In this case, the movement of robot1 will impact the movement of robot2. In other words, the optimal track of robot2 depends on the track of robot1. If we want to apply DP, we need to record the whole track of robot1 as the state. The number of sub-problems is too much.

// In fact, in any case, when we move one robot several steps earlier than the other, the movement of the first robot will impact the movement of the second robot.

// Unless we move them synchronously (i.e., move one step of robot1 and robot2 at the same time).

// Let's define the DP state as (row1, col1, row2, col2), where (row1, col1) represents the location of robot1, and (row2, col2) represents the location of robot2.

// If we move them synchronously, robot1 and robot2 will always on the same row. Therefore, row1 == row2.
    
class Solution {
public:
    int dp[70][70][70];
    int helper(int r1,int c1,int c2,int n,int m,vector<vector<int>> &grid)
    {
        if( r1>=n ||c1<0 || c1>=m || c2<0 || c2>=m ) return INT_MIN;
        
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];

        int ans=grid[r1][c1];
        
        if(c1!=c2) ans+= grid[r1][c2];
        
        int temp=0;
        //There are nine possible next step for current position {-1,0,1} for each robot
        //     ROBOT1 | ROBOT2
        // ------------------------
        //  LEFT DOWN |  LEFT DOWN
        //  LEFT DOWN |       DOWN
        //  LEFT DOWN | RIGHT DOWN
        //       DOWN |  LEFT DOWN
        //       DOWN |       DOWN
        //       DOWN | RIGHT DOWN
        // RIGHT DOWN |  LEFT DOWN
        // RIGHT DOWN |       DOWN  
        // RIGHT DOWN | RIGHT DOWN 
        
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                temp=max(temp,helper(r1+1,c1+i,c2+j,n,m,grid));
            }
        }
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,m-1,n,m,grid);    // Return 0 if ans equals to INT_MIN
    }
};
