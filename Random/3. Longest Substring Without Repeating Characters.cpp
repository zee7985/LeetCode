3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


// We use Set to store the characters in current window [i, j) (j=i initially).
//  Then we slide the index j to the right. If it is not in the HashSet, we slide j further. 
//  Doing so until s[j] is already in the HashSet. At this point, we found the maximum size of 
//  substrings without duplicate characters start with index i. If we do this for all i, we get our answer.
class Solution {
public:
    //1. Generate all substring and check whether that substring contain repeated char or not
    int lengthOfLongestSubstring(string A) {
        int n = A.length();
        if(n == 0)
            return 0;
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map<char,int> m;
            int c = 0;
            for(int j=i; j<n; j++)
            {
                if(m.find(A[j]) == m.end())
                {
                    m[A[j]]++;
                    c++;
                }
                else
                    break;
            }
            ans = max(ans,c);
        }
        
        return ans;
    }
    
    //2.SLiding Window
    //Time complexity : O(2n) = O(n)O(2n)=O(n). In the worst case each character will be 
    //visited twice by i and j.
    int lengthOfLongestSubstring(string s) {
        set<char> hs;
        int n=s.length();
        int max_=0;
       
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(hs.find(s[j])==hs.end())
            {
                hs.insert(s[j]);
                j++;
                max_=max(max_,j-i);
            }
            else{
                hs.erase(s[i]);
                i++;
            }
        }
        return max_;
        
    }
};
