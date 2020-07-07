37. Sudoku Solver
Hard

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.

// //1. REcursion.
// class Solution {
// public:
//     bool canplace(vector<vector<char>>& arr,int i,int j,int n,int number)
//     {  //row n column check
//         for(int x=0;x<n;x++)
//         {
//         if((arr[i][x]==number +'0') || (arr[x][j]==number +'0'))
//         {
//             return false;
//         }
//     }
//     //int rx=sqrt(n);
//     int sx=(i/3)*3;
//     int sy=(j/3)*3;

//     for(int q=sx;q<sx+3;q++)
//     {
//         for(int w=sy;w<sy+3;w++)
//         {
//             if(arr[q][w]==number +'0')
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
//     }
    
//     bool sudoku(vector<vector<char>>& arr,int i,int j,int n)
//     {
//     //print
//     if(i==n)
//     {
//         // for(int i=0;i<n;i++)
//         // {
//         //     for(int j=0;j<n;j++)
//         //     {
//         //         cout<<arr[i][j]<<" ";
//         //     }   
//         //     cout<<endl;
//         // }
//         return true;
//     }
//     if(j==n)
//     {
//        return sudoku(arr,i+1,0,n);
//     }
        
//     if(arr[i][j]!='.')
//     {
//       return sudoku(arr,i,j+1,n);
//     }
        
//     for(int number=1;number<=n;number++)
//     {
//         if(canplace(arr,i,j,n,number))
//         {
//             arr[i][j]=number + '0';

//             bool couldwesolve=sudoku(arr,i,j+1,n);
//             if(couldwesolve==true)
//             {
//                 //cout<<arr[i][j];
//                 return true;

//             }
//          }
//     }
//     arr[i][j]='.';//acktracking
//     return false;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         bool issolve=sudoku(board,0,0,9);
//     }
// };

//2. Bitmasking

class Solution {
public:
    const int n = 9;
    bool rows[10][10];
    bool cols[10][10];
    bool blocks[10][10];
    
    bool solve(int row,int col,vector<vector<char>>& board)
    {
        if(row==n)
        {
            return true;
        }
        
        if(col==n)
        {
            return solve(row+1,0,board);
        }
        
        if(board[row][col]!='.') return solve(row,col+1,board);
        
        bool res = false;
        for(int i = 1;i<=9;i++)
        {
            int id = 3*(row/3) + col/3;
            
            if(!rows[row][i] && !cols[col][i] && !blocks[id][i])
            {
                rows[row][i] = cols[col][i] = blocks[id][i] = 1;
                
                board[row][col] = char(i+'0');
                
                bool res = solve(row,col+1,board);
                if(res) return true;
                
                rows[row][i] = cols[col][i] = blocks[id][i] = 0;
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                
                int cur = board[i][j] - '0';
                rows[i][cur] = 1;
                cols[j][cur] = 1;
                int id = 3*(i/3) + j/3;
                
                blocks[id][cur] = 1;
            }
        }
        
        solve(0,0,board);
    }
};
