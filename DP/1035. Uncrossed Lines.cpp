1035.Uncrossed Lines

Medium

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.


HINT:
this problem is equivalent to longest common subsequence.

Let dp[i + 1][j + 1] be the maximum number of connecting lines between A[0..i] and B[0..j].

dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1] )         if A[i] != B[j]
               1 + dp[i][j]                          if A[i] == B[j]
dp[0][0] = 0

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2








class Solution {
public:
    
     int maxUncrossedLines(vector<int>& A, vector<int>& B) {
         vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
        
    
    
//     //Recursion-TLE
//     int maxRecur(int i,int j,vector<int>& A, vector<int>& B)
//     {
        
//         if(i==A.size() || j==B.size()){
//             return 0;
//         }
        
//         int res=0,res1=0,res2=0;
        
//         if(A[i]==B[j]){
//             res1=1+ maxRecur(i+1,j+1,A,B);
//         }
        
//         res2=max(maxRecur(i+1,j,A,B),maxRecur(i,j+1,A,B));
        
//         res=max(res1,res2);
        
//         return res;
//     }
    
//     int maxUncrossedLines(vector<int>& A, vector<int>& B) {
//         return maxRecur(0,0,A,B);
//     }
};