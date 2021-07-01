 Gray Code

Solution
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

1 <= n <= 16
  
class Solution {
public:
    //Step 1: For 1 bits gray code : [0,1]
    //Step 2 : Follow stps :
//               take n-1 bits gray code and then 
//                 add "0" to each element  of n-1 bits gray code
//                 add "1" to each element  of n-1 bits gray code ,reverse this and combine both 
                  
//     eg- 1 bits :[0,1]
//         2 bits : [00,01] 
//                  [10,11]-> reverse ->[11,10]
                     
//         Ans= combine:[00,01,11,10]
//         Similarly for 3,4,5 bits
                
    vector<int> grayCode(int n) {  
        
        vector<int> result;
        
        vector<string> answer = grayCodeUtil(n); 
        
        for(int i = 0; i < answer.size(); i++) { 
            
            int element = binToDec(answer[i]); 
            
            result.push_back(element);
        } 
        
        return result;
    } 
    
    vector<string> grayCodeUtil(int n) { 
        
        if (n == 1) { 
           
            return {"0", "1"};
        } 
        
        vector<string> res = grayCodeUtil(n-1); 
        vector<string> newRes; 
        
        for(int i = 0; i < res.size(); i++) { 
            string current = res[i]; 
            current = "0" + current; 
            newRes.push_back(current);
        } 
        
        for(int i = res.size()-1; i >=0 ; i--) { 
            string current = res[i]; 
            current = "1" + current; 
            newRes.push_back(current);
        } 
        
        return newRes;
    } 
    
    int binToDec(string binary) { 
        
        int decimal = 0; 
        
        int placeValue = 0; 
        
        for (int i = binary.length()-1; i >=0 ; i--) { 
            
            decimal = decimal + (pow(2, placeValue) * (binary[i] - '0')); 
            placeValue++; 
        } 
        
        return decimal;
    }
};
