22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


class Solution {
public:
    void generateParenthesis(string s, int n, int open, int close,vector<string>& ans,int i)
    {
	    if(i==2*n)
	    {
		    ans.push_back(s);
	    }
        
        //two recursive calls
        
	    if(open < n)                                                //opening bracket should be less than n
	    {
		    generateParenthesis(s+ "("  ,n,open+1,close,ans,i+1);
	    }
	    if(close<open)                                              //closing bracket should be less than opening bracket
	    {
		    generateParenthesis(s + ")" ,n,open,close+1,ans,i+1);
	    }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
	    string s;
	    generateParenthesis(s,n,0,0,ans,0);
	    return ans;
    }
};