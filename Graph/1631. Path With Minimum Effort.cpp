1631. Path With Minimum Effort
Medium

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

class Solution {
public:
    // Here we have use binary search to find the max permissible value for a particular dfs 
    // Binary search to find the best minimum value for which we can find the path(i.e If we are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.)
    
    // Time: O(m * n * log(INT_MAX))
    // space: O(m * n)
    
    bool helper(int i,int j,int n,int m,int mid,vector<vector<int>>&h,int visited[100][100])
    {
        if(i==n-1 && j==m-1)
        {
            return true;
        }
        
        bool ans=false;
        visited[i][j]=true;
        
        //Traverse all the four directions
        if(i>0 && visited[i-1][j]==false && abs(h[i][j]-h[i-1][j])<=mid)
        {
            ans=ans||helper(i-1,j,n,m,mid,h,visited);
        }
        if(i<n-1 && visited[i+1][j]==false && abs(h[i][j]-h[i+1][j])<=mid)
        {
            ans=ans||helper(i+1,j,n,m,mid,h,visited);
        }
        if(j>0 && visited[i][j-1]==false && abs(h[i][j]-h[i][j-1])<=mid)
        {
            ans=ans||helper(i,j-1,n,m,mid,h,visited);
        }
        if(j<m-1 && visited[i][j+1]==false && abs(h[i][j]-h[i][j+1])<=mid)
        {
            ans=ans||helper(i,j+1,n,m,mid,h,visited);
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int ans=INT_MAX;
        int s=0;
        int e=INT_MAX;
        while(s<=e)
        {
            int mid=s + (e-s)/2;
            int visited[100][100]={0};
            if(helper(0,0,n,m,mid,heights,visited))  // If there is ans then update, restrict our absolute diff
            {
                ans=min(ans,mid);
                e=mid-1;    //  Now find for value less than mid,as all the value greater than mid will give ans
            }
            else
            {
             s=mid+1;   
            }
        }
        return ans;
    }
};
