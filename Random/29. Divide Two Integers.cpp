29. Divide Two Integers
Medium


Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note:

Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.
 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
  
 class Solution {
public:
    // Divide without using division 
    //Basic idea: c=a/b 
    //log both sides log(c)=log(a/b) =log(a)- log(b)
    //c= = e^(log(a)-log(b))
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        
        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
        int sign=1;
        if(dividend< 0 && divisor>0  || dividend>0 && divisor<0)
        {
            sign=-1;
        }
        res=sign*res;
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }
};
