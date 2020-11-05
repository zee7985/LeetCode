994. Rotting Oranges
Medium


In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.


class Solution {
public:
    int dirX[4]={0,0,1,-1};
    int dirY[4]={-1,1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges=0;
        queue<vector<int>>q; // push all the rotten oranges in the queue with time elpased 0,// ith, jth, time
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j,0});
                }
                else if(grid[i][j]==1)
                {
                    freshOranges++;
                }
            }
        }
        
        // if there is no fresh orange, no need to look for, answer is 0
        if(freshOranges==0) return 0;
        
        int time=0;
        while(!q.empty())
        {
            vector<int> curr=q.front(); q.pop();
            int a=curr[0];
            int b=curr[1];
            time=curr[2];
            
            for(int i=0;i<4;i++)
            {
                int x= a+ dirX[i];
                int y= b+ dirY[i];
                
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y]==1)
                {
                    q.push({x,y,time+1});
                    grid[x][y]=2;
                }
            }
        }
        
        // if after the bfs, there is still any fresh orange left, answer is -1
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                   return -1;      
                }
            }
        }
        
        return time;
        
    }
};






