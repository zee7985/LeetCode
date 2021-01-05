583. Delete Operation for Two Strings
Medium

Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.

class Solution {
public:
    //Similar to LCS 
    // In order to determine the minimum number of delete operations needed, we can make use of the length of the longest common sequence           among the two given strings s1s1 and s2s2, say given by lcslcs. If we can find this lcslcs value, we can easily determine the required          result as m + n - 2*lcsm+n−2∗lcs. Here, mm and nn refer to the length of the two given strings s1s1 and s2s2.
    int dp[501][501];
    int helper(string word1,string word2,int i,int j)
    {
        if (i==word1.length()) 
            return word2.length()-j; 
  
        // If second string is empty
        // remove all characters of first string 
        if (j==word2.length()) 
            return word1.length()-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(word1[i]==word2[j])
        {
            return dp[i][j]=helper(word1,word2,i+1,j+1);
        }
        return dp[i][j]=1+min(helper(word1,word2,i+1,j),helper(word1,word2,i,j+1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return helper(word1,word2,0,0);
    }
};
