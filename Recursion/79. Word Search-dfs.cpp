79. Word Search
Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3



class Solution {
public:
    bool findFn(vector<vector<char>>& board,int i,int j,int k,string word)
    {
        
        
       if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k])
        {
           return false;
        }
        
        if(k==word.size()-1) return true;
            
        char x=board[i][j];
        board[i][j]='0';
        bool res=false;
        res =res || findFn(board,i-1,j,k+1,word);           
        res= res || findFn(board,i+1,j,k+1,word);
        res= res || findFn(board,i,j+1,k+1,word); 
        res= res || findFn(board,i,j-1,k+1,word);
        
        board[i][j]=x;  //backtrack
        
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {      
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])     //will call dfs only when first char is same
                {
                    if(findFn(board,i,j,0,word))
                    {
                        return true;
                    }
                }
            }
        }
        return false;        
    }
};
