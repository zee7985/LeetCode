859. Buddy Strings
Easy

Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.

// if A.length() != B.length(): no possible swap

// If A == B, we need swap two same characters. Check is duplicated char in A.

// In other cases, we find index for A[i] != B[i]. There should be only 2 diffs and it's our one swap.

class Solution {
public:
    
   bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
       
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
        {
            return true;
        }
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i)
        {
            if (A[i] != B[i]) dif.push_back(i);
        }
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];  //diff should be only 2. For eg-bacd ,abdc  -Ans should be                                                                                             //false(diff 4)
   }
}; 
