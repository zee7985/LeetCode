The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

class Solution {
public:
        //By bitmasking -can be done by bool or bitset 
    bitset<30> col,diag1,diag2;
   // vector<30> col,diag1,diag2;
    
    void solve(int row,int n,int &ans)
    {
        if(row==n)
        {
            ans++;
            return;
        }
        
        for(int c = 0;c<n;c++)
        {
            if(!col[c] && !diag1[row + c] && !diag2[row-c+n])
            {
                col[c] = 1;
                diag1[row + c] = 1;
                diag2[row-c + n] = 1;
                //cur[row][c] = 'Q';
                
                solve(row + 1,n,ans);
                
                col[c] = 0;
                diag1[row + c] = 0;
                diag2[row-c + n] = 0;
                //cur[row][c] = '.';
                
            }
        }
         
    }
    
    int totalNQueens(int n) {
       // col.resize(n);
       // diag1.resize(2*n+1);
       //  diag2.resize(2*n+1);
        
//         vector<string> cur(n);
//         string s = string(n,'.');
        
//         for(auto & x : cur) x = s;
        
        int row = 0;
        int ans=0;
        solve(row,n,ans);
        
        return ans;
        
    }
};
