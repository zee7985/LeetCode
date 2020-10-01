139. Word Break
Medium


Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

class Solution {
public:
    
    
    bool wordPresent(string word,vector<string>& wordDict)
    {
        for(string s:wordDict)
        {
            if(s.compare(word)==0)
            {
                return true;
            }
        }
        return false;
    }
    
    bool Helper(string s, int idx,vector<string>& wordDict,vector<int> &dp)
    {
        if(s.length()==idx)
        {
            return true;
        }
        string temp="";
        if (dp[idx] != -1) return dp[idx];
        
        
        for(int i=idx;i<s.length();i++)
        {
            temp+=s[i];
            if(wordPresent(temp,wordDict))
            {
               if(Helper(s,i+1,wordDict,dp))
               {
                   dp[idx]=1;
                   return true;
               }
            }
        }
        dp[idx]=0;
        return false;
    }
    bool wordBreak(string s,vector<string>& wordDict) {
        vector<int> dp(s.length(), -1); 
        return Helper(s,0,wordDict,dp);
    }
};

