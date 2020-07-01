1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium


Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

 Hint converting to int will lead to TLE

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0



// Goal: make the string s=="1".

// Perform operation on last bit.
// if last-bit=0. Indicates no is multiple of 2. Divide by 2 removes last 0
// if last-bit=1. Indicates no is odd. Add 1.
// {1+1 = 0(at position),1(carry)}. Assign 0 to last bit and search for 0 before last bit.
// If 0 is found, change that to 1 and all the characters after that 1 change to 0.
// If 0 is not found, insert 1 at beginning of the string and all other elements will be changed to 0.
class Solution {
public:
    int numSteps(string s) {
        int count=0;
        
        while(s!="1"){
            if(s.back()=='0'){   // Means divide by 2
                s.pop_back();
                count++;
            }
            else{                            //odd
                bool check=false;            //bool to check if all the no is 1 for eg: 1111
                                            //on adding 1 it will become 0000 with carry 1 so we need to add 1 at he starting of the string to make it(10000)
                
                for(int i=s.size()-1;i>=0;i--){  //Traverse through the string from back
                    if(s[i]=='0'){               // till we find a zero and equate it to 1
                        s[i]=1;
                        check=true;               //For eg- 110111 (+1) == 111000                 
                        break;                    //           |
                    }                             //           |
                    else{                         //           V
                        s[i]='0';                 // And all the string till that 0 equal to "0"
                                                    
                    }
                }
                if(!check){                      
                    s="1"+s;                     //If all 1 i.e 1111
                }
                count++;
            }
        }
        return count;
    }
};