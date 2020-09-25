980. Unique Paths III
Hard

On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

Note:

1 <= grid.length * grid[0].length <= 20

class Solution {
public:
    
    //1. Recursion No memo because
    // Memo needs to encode state of grid. You are caching number of unique paths from intermediate point to destination.
    //It is not same for different states of grid.
    // Essentially, given a grid, depending on which nodes you have already covered, then from a given empty node, you will get a certain unique            number of paths. If the set of nodes already covered is different, you may get different number of paths.



    int z=0,sr,sc,count=0,r,c;
    void findcount(vector<vector<int>>& grid,int sr,int sc,int z)
    {    
         if(sr>=r||sc>=c||sr<0||sc<0 ||grid[sr][sc]==5 || grid[sr][sc]==-1) return; 
        
         if( z==0 &&grid[sr][sc]==2) {   //if all zero elemnt visited and final point is 2
             count++;
             return;
         }
         if(grid[sr][sc]==0)
         {
             z--;  
         }
        
         int temp=grid[sr][sc];
        
         grid[sr][sc]=5;
        
         findcount(grid,sr+1,sc,z);
         findcount(grid,sr-1,sc,z);
         findcount(grid,sr,sc-1,z);
         findcount(grid,sr,sc+1,z);
         grid[sr][sc]=temp;
        
         return;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        
        for(int i=0;i<r;i++)
           { 
               for(int j=0;j<c;j++)
                { int y=grid[i][j];
                   if(y==0) 
                   {
                       z++; //count total no of zeros
                   }
                    if(y==1)
                    {
                        sr=i;
                        sc=j;
                    }
                }
           }
        findcount(grid,sr,sc,z);
        return count;
        
    }
};
