1249. Minimum Remove to Make Valid Parentheses
Medium


Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.

class Solution {
public:
//     Each prefix of a balanced parentheses has a number of open parentheses greater or equal than closed  parentheses, similar idea with each suffix
//     First, create a count variable for storing the number of opening or closing brackets as per our need.

//     Initialize open=0. For this step, we will use open for storing the number of open brackets.
//     Then, iterate the string s from start and at each iteration:
//     if open bracket found, then increase count of open.
//     if close bracket found, then check if no. of close brackets > no. of open brackets, then mark that character in s by replacing it by 1, else increase  the count of closed( as matching parentheses found ).
        
        
//     Similarly repeat the above steps in reverse
      
    //O(n) with O(1) space
    string minRemoveToMakeValid(string s) {
        int open=0,closed=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
               // cout<<closed<<" "<<open<<"\n";
                if(closed>=open)
                {
                    s[i]='1';
                }
                else
                {
                    closed++;
                }
                
            }
        }

        open=0,closed=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                closed++;
            }
            else if(s[i]=='(')
            {
                if(open>=closed)
                {
                    s[i]='1';
                }
                else
                {
                    open++;
                }
            }
        }
        
        string res="";
        for(auto i: s)
        {
            if(i!='1')
            {
                res+=i;
            }
        }
        return res;
    }
};
