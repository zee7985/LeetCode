856. Score of Parentheses
Medium


Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int ans=0;
        int cnt=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                st.push(cnt);
                cnt=0;
            }
            else
            {
                if(cnt==0) cnt++;      // Closing bracket -()   Rule 1
                else cnt=2*cnt;       // Nested Loop (())   Rule 3
                cnt+=st.top();        // Rule 2    ()()  connect to prev
                st.pop();
                
            }
        }
        return cnt;
    }
};

// Eg-()
// cnt=0
    
// i=0 st=[0];  cnt=0
// i=1 st=[]    cnt=0  ,so cnt++; cnt+=st.top() cnt=1 

    
// Eg-"(()(()))"
    
//     i=0   st=[0];         cnt=0
//     i=1   st=[0,0]        cnt=0
//     i=2   st=[0]          cnt=cnt+1    cnt+=st.top()   cnt=1 + 0
//     i=3   st=[0,1]        cnt=0
//     i=4   st=[0,1,0]      cnt=0
//     i=5   st=[0,1]        cnt=cnt+1    cnt+=st.top()   cnt=1 + 0
//     i=6   st=[0]          cnt=2*cnt    cnt+=st.top()   cnt=2 + 1
//     i=7   st=[]           cnt=2*cnt    cnt+=st.top()   cnt=6 + 0
    
    
