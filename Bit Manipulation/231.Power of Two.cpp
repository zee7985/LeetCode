231.Power of Two

Solution
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false


Hint :check that there is only one Bit

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        if(count==1){
          return true;  
        }
        return false;
    }
}; 