459. Repeated Substring Pattern

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution {
public:
    //1.KMP
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int> dp(n,0);
        
        int i=1;
        int j=0;
        
        for(i=1;i<n;)
        {
            if(s[i]==s[j])
            {
                j++;
                dp[i]=j;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=dp[j-1];
                }
                else
                {
                    dp[i]=0;
                    i++;
                }
            }
        }
        //If the last index is zero, we know we don't have a repated substring
        if(dp[n-1]==0)
        {
            return false;
        }
        
        //Get the value of the last substring
        int last = n-dp[n-1] ;
        
        
         //If we can divide the value of the last substring into the KMP's last element then we know we have a repeated substring 
        if(dp[n-1]%last==0)
        {
            return true;
        }
    return false;
        
    }
    
    
};


//2.

// The key here is to double the string, that is, append the string to itself. In this way, the pattern would be duplicated.
// On removing the first and the last characters, if there exists some pattern, we would still be able to find the original string somewhere in the middle, taking some characters from the first half and some from the second half.

// For example,

// Example 1.

// s = "abab"
// s+s = "abababab"

// On removing the first and the last characters, we get:
// (s+s).substr(1, 2*s.size()-2) = "bababa"

// This new string, "bababa" still contains the original string, "abab".
// Thus there exists some repeated pattern in the original string itself.
// Example 2.

// s = "aba"
// s+s = "abaaba"

// On removing the first and the last characters, we get:
// (s+s).substr(1, 2*s.size()-2) = "baab"

// This new string, "baab" does not contain the original string, "aba".
// This implies that there does not exist any pattern in the original string itself.
// Code

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};
