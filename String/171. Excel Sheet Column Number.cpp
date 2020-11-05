171. Excel Sheet Column Number
Easy

1374

181

Add to List

Share
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW"

class Solution {
public:
    // A = 1 = 26 * 0
    // AA = 26 + 1 = 26 * 1 + 1
    // BA = 26 + 26 + 1 = 26 * 2 + 1
    // CA = 26 + 26 + 26 + 1 = 26 * 3 + 1
    // ZY = 26*26 +25
    int titleToNumber(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans=ans*26;
            ans+=(s[i]-'A' +1);
        }
        return ans;
    }
};
