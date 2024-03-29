13. Roman to Integer
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4
Example 3:

Input: s = "IX"
Output: 9
Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
class Solution {
public:
    
    // start from back of the string and add all char and delete only those whose values is lower than next char
    //Eg- IX   Add 10 for X and subtract 1 for I as it's value is less than X
    int h(char ch)
    {
        if(ch=='I') return 1;
        if(ch=='V') return 5;
        if(ch=='X') return 10;
        if(ch=='L') return 50;
        if(ch=='C') return 100;
        if(ch=='D') return 500;
        if(ch=='M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        
        int sum=h(s[s.length()-1]);
        for(int i=s.length()-2;i>=0;i--)
        {
            if(h(s[i]) >= h(s[i+1]))
            {
                sum+=h(s[i]);
            }
            else
            {
                sum-=h(s[i]);
            }
        }
        return sum;
    }
};
 


//12. Integer to Roman
class Solution {
public:
    string intToRoman(int num) 
    {
        
        vector<string> ones{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        vector<string> tens{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        vector<string>hundreds { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        vector<string>thousands{ "", "M", "MM", "MMM" };
    
        int th = num/1000;
        num -= th*1000;
        
        int h = num/100;
        num -= h*100;
        
        int t = num/10;
        int o = num - t*10;
    
        return thousands[th]+hundreds[h]+tens[t]+ones[o];
    }
};
