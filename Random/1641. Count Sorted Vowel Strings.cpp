1641. Count Sorted Vowel Strings
Medium
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 

class Solution {
 public:
    // combinatoric problem: arranging n stars and 4 bars, (n+4) slots choose 4
    // stars and bars: https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)

    // For n =1, 5 slots, _ _ _ _ _, pick 4 slots for the bars:

    // *| | | | = a
    // |* | | | = e
    // | |* | | = i
    // | | |* | = o
    // | | | |* = u
    
    // For n =2, 6 slots, _ _ _ _ _ _ , pick 4 slots for the bars:

    // **| | | | = aa
    // |** | | | = ee
    // | |** | | = ii
    // | | |**| = oo
    // | | | |** = uu
    // *|* | | | = ae
    // *| |* | | = ai
    // *| | |* | = ao
    // *| | | |* = au
    
    // answer = (n+4) choose 4 = (n+4)(n+3)(n+2)(n+1)/4!
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+2)*(n+1)/24;    
    }
};
