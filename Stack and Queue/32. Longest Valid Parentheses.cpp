32. Longest Valid Parentheses
Hard

4503

170

Add to List

Share
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
  
 class Solution {
public:
//     Eg-  () (()) ) () ) ()
//                  6    9
        
//     We will be using stack and push bracket index into the stack and at the end we will get the index of bracket which we break our balanced parantheses.
//     For eg-[6,9] will be in stack , So our balanced substring will be 0-6 , 6-9 , 9-11
        
//     So ,max=max(i -newTop, max) 
//         i : currIndex
//         newTop : index of element at the top of the stack
    
//     Step 1:st.push(-1) -Important to push
            
//     i=0   st=[-1,0]    Push                                                   max=0
//     i=1   st=[-1]      Resolve ')': pop()     newMax=1-(-1)=2                 max=2
//     i=2   st=[-1,2]
//     i=3   st=[-1,2,3]  Push                                                   max=2
//     i=4   st=[-1,2]    Resolve ')': pop()     newMax=4-(2)=2                  max=2
//     i=5   st=[-1]      Resolve ')': pop()     newMax=5-(-1)=6                 max=6
//     i=6   st=[]        Resolve ')': pop()     stack empty() : that means breaking pt : Push into stack 
//     i=7   st=[6,7]     Push
//     i=8   st=[6]       Resolve ')': pop()     newMax=8-(6)=2                  max=6
//     i=9   st=[]        Resolve ')': pop()     stack empty() : that means breaking pt : Push into stack
//     i=10  st=[9,10]    Push
//     i=11  st=[9]       Resolve ')': pop()     newMax=11-(9)=2                 max=6
        
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = max(maxans, i - stack.top());
                }
            }
        }
        return maxans;
    }
    
    //2nd Method -Similar to score of parantheses
//      int longestValidParentheses(string s) {

//         int chain = 0;
//         int ans = 0;
//         stack<int> st;

//         for (char ch : s)
//         {
//             if (ch == '(')
//             {
//                 st.push(chain);
//                 chain = 0; // new chain started
//             }
//             else {
//                 if (!st.empty())
//                 {
//                     // chain for (()) and st.top() for ()() and 2 for cur_balance
//                     chain = chain + st.top() + 2;
//                     st.pop();

//                     ans = max(ans, chain);
//                 }
//                 else chain = 0; // New start // as substring
//             }
//         }

//         return ans;

//     }
};
