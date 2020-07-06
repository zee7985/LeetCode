3. Longest Substring Without Repeating Characters
Medium


Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


// We use Set to store the characters in current window [i, j) (j=i initially).
//  Then we slide the index j to the right. If it is not in the HashSet, we slide j further. 
//  Doing so until s[j] is already in the HashSet. At this point, we found the maximum size of 
//  substrings without duplicate characters start with index i. If we do this for all i, we get our answer.
class Solution {
public:
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