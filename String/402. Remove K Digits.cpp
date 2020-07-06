402. Remove K Digits
Medium

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


class Solution {
public:
    
    //intuition is to make increasing string as much as possible and when a smaller 
    //element comes remove all the char greater than the smaller element and till k times 
    string removeKdigits(string str, int k) {
        
           string ans = "";                                         // treat ans as a stack in below for loop
       
       for (char c : str) {
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();                                  // make sure digits in ans are in ascending order
                                                                // eg-135034 and k=3 ans =34
               k--;                                             // remove one char
           }
           
           if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0'
       }
       
       while (ans.length() && k--) { ans.pop_back(); }          // if string is in increasing and we havent removed k element 
                                                                //then remove from back  eg-1234 and k=2 ans =12
                                                                
        
       
       return ans.empty() ? "0" : ans;
    }
};