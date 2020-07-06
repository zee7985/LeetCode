784. Letter Case Permutation
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

class Solution {
public:
     void permutationHelper(string S,int idx,string ans,vector<string> &v){
         if(idx==S.length()){
             v.push_back(ans);
             return;
         }
         char ch=S[idx];
         if(isdigit(ch)){
             permutationHelper(S,idx+1,ans+ch,v);
         }
         else{
             permutationHelper(S,idx+1,ans+ch,v);    Subsequence method
             if(ch>='a' && ch <='z'){
                 ch=ch -'a' + 'A';
                 permutationHelper(S,idx+1,ans+ch,v);
             }
             else if(ch>='A' && ch <='Z'){
                   ch=ch - 'A' + 'a';
                 permutationHelper(S,idx+1,ans+ch,v);
             }
         }
           
     }
    vector<string> letterCasePermutation(string S) {
        vector<string> v;
        permutationHelper(S,0,"",v);
        return v;
    }
};



