You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
Example 2:

Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
Example 3:

Input: words = ["abcd"], target = "abcd"
Output: 1
Example 4:

Input: words = ["abab","baba","abba","baab"], target = "abba"
Output: 16
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters

// Store a frequency table of characters by position. So for eg., in position 0, count the number of a’s, b’s, c’s, etc 
//across index 0 of all words
// similarly number of of a’s, b’s, c’s, etc in position 1,2, and so on.
// Run a dfs that takes two inputs - the current position in word (int i), and the current position in target (int j)

#define ll long long 
#define mod 1000000007

class Solution {
public:
	ll dp[1001][1001];
	ll help(int i,string &t,vector<vector<int>>&temp,int j)
	{

		if(i==t.size())return 1;      // If we exceed target's length, we've matched everything in target
        
		if(j==temp.size())return 0;   // Else if you exceed word's length, we haven't matched target
        
		if(dp[i][j]!=-1)return dp[i][j];
		ll ans=0;
        
		ans+=help(i,t,temp,j+1);      //skip
		ans%=mod;
		ans+=(temp[j][t[i]-'a']*help(i+1,t,temp,j+1))%mod;  //if freq =0 ,then add 0 to ans add the freq to the ans
		return dp[i][j]=ans%mod;
	}
	int numWays(vector<string>& words, string t)
	{
		int x=words[0].size();
		vector<vector<int>>temp(x,vector<int>(26,0));
 
		for(auto a:words)                         // Build a frequency table indexed by word position
		{                                         // for eg-acca,bbbb,caca
			for(int i=0;i<a.size();i++)           // number of element present for index 0  : 1a,1b,1c,0d,0e.,,,,,,,,,,
			{                                     //                           for index 1  : 1c,1b,1a
				temp[i][a[i]-'a']++;              //                           for index 2  : 2c,1b
			}                                     //                           for index 3  : 2a,1b
		}
		memset(dp,-1,sizeof dp);
		return help(0,t,temp,0);

	}
};
