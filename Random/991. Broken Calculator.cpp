991. Broken Calculator
Medium

On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

 

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.
Example 3:

Input: X = 3, Y = 10
Output: 3
Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
Example 4:

Input: X = 1024, Y = 1
Output: 1023
Explanation: Use decrement operations 1023 times.
 

Note:

1 <= X <= 10^9
1 <= Y <= 10^9

class Solution {
public:
    //Here we are making Y equal to X(dividing and adding ) instead X to Y(multiplying/subtracting)
    // So the X -> Y and Y->X are problems that share the same shortest path, with the least operations for both.
    // Intuition of doing Y to X is from the observation that odd Y must do '+1', which is good, you only need to      consider even Y. But X can go either '-1' and '*2' if starting at X(so two operation for single X).That's        why reversed process.
       
    //Greedy-O(logY)
    int brokenCalc(int X, int Y) {
        if(Y<X)
        {
            return X-Y;
        }
        int steps=0;
        
        while(Y>X)
        {
            if(Y%2==0)
            {
                Y=Y/2;
            }
            else
            {
                Y=Y+1;
            }
            steps++;
        }
        return steps + X-Y;
        
    }
};
