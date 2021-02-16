1680. Concatenation of Consecutive Binary Numbers
Medium

Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:

1 <= n <= 105

class Solution {
public:
    //Appending binary string at the end of an existing string will lead to left shift effect by the size of appended string
    
    //            N=1   val=1    string=1        2^0
    //(append 2)  N=2   val=6    string=1 10     here,val of 1 at idx 0 will become 2^2 from 2^0 after append
    //(append 3)  N=1   val=27   string=110 11  so left shift the existing string by the noOfdigits of currStr      
    //                                             (val=val*pow(2,noOfdigits of currNo) + currNo))
    //                                             (val=6*2^2 + 3)=27  
    
    
    const int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long int val=0;
        
        for(int i=1;i<=n;i++)
        {
            int noOfdigits=1 + (int)log2(i);    // count no of digits in current no to left shift our ans 
            val=((val<<noOfdigits)+i)%mod;
        }
        return val;
    }
};
