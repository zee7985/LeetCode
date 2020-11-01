1638. Count Substrings That Differ by One Character
Medium

Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("Aba", "Baba")
("Aba", "baBa")
("aBa", "bAba")
("aBa", "babA")
("abA", "Baba")
("abA", "baBa")
The Capitalised portions are the substrings that are chosen from s and t.
​​Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("Ab", "Bb")
("Ab", "bB")
("AB", "BB")

​​​​The capitalised portions are the substrings that are chosen from s and t.
Example 3:
Input: s = "a", t = "a"
Output: 0
Example 4:

Input: s = "abe", t = "bbc"
Output: 10
 

Constraints:

1 <= s.length, t.length <= 100
s and t consist of lowercase English letters only.

class Solution {
public:
//     We compare strings starting from s[i] and t[j], and track the number of mismatched characters miss:

//     0: continue our comparison
//     1: we found a substring - increment res and continue our comparison
//     2: break from the loop.
    int countSubstrings(string s, string t) {
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                int x=i;
                int y=j;
                int d=0;
                while(x < s.size() && y < t.size())
                {
                    if(s[x]!=t[y]) d++;
                    if(d==1) ans++;          //Differ by One Character only  
                    if(d==2) break;          // otherwise break if diff greater than 1
                    x++;y++;
                }
            }
        }
        return ans;
    }
};
