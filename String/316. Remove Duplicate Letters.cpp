316. Remove Duplicate Letters
Medium


Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters

// First, given "bcabc", the solution should be "abc". If we think about this problem intuitively, you would sort of go from the beginning of the string and start removing one if there is still the same character left and a smaller character is after it. Given "bcabc", when you see a 'b', keep it and continue with the search, then keep the following 'c', then we see an 'a'. Now we get a chance to get a smaller lexi order, you can check if after 'a', there is still 'b' and 'c' or not. We indeed have them and "abc" will be our result.

// Come to the implementation, we need some data structure to store the previous characters 'b' and 'c', and we need to compare the current character with previous saved ones, and if there are multiple same characters, we prefer left ones. This calls for a stack.

// After we decided to use stack, the implementation becomes clearer. From the intuition, we know that we need to know if there are still remaining characters left or not. So we need to iterate the array and save how many each characters are there. A visited array is also required since we want unique character in the solution. The line while(!stack.isEmpty() && stack.peek() > c && count[stack.peek()-'a'] > 0) checks that the queued character should be removed or not, like the 'b' and 'c' in the previous example. After removing the previous characters, push in the new char and mark the visited array.

// Time complexity: O(n), n is the number of chars in string.

// Space complexity: O(n) worst case.
class Solution {
public:
    string removeDuplicateLetters(string s) {
       int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']=i;
        }
        vector<bool> visited(26,false);
        stack<int> st;
        
        for(int i=0;i<s.length();i++)
        {
            int temp=(s[i]-'a');
            if(visited[temp]) continue;
            
            while(!st.empty() && temp < st.top()  && i < freq[st.top()])   //eg-if b<c   and there is another c in the latter part then we can take //                                                                          that c and discard this c to make lexicographically smaller subsequence
            {
                visited[st.top()]=false;
                st.pop();
            }
            st.push(temp);
            visited[temp]=true;
        }
        string str="";
        while(!st.empty())
        {
            str=(char)(st.top()+'a') + str;
            st.pop();
        }
        return str;

    }
    
};
