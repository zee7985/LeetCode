754. Reach a Number
Medium

You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9]

class Solution {
public:
    //Few Observations :
    //1. Ans for negative and positive number is same(so abs(target))
    //2. Every even no can be generated by some compuation
         // 2 : 1-2+3
         // 4 : -1+2+3
         // 6 : 1-2+3+4
         // 8 : -1+2+3+4
         // 10: 1+2+3+4
    
    //Steps: if sum of n ((1+2+3+ ....+steps)==target), return steps;
    // If sum>target  ,then find difference sum-target
        //If diff is even,return step (Using obs 2 -i.e we can negate some value and it will be generate target)
        // Else if difference is odd,then our aim is to make it even
            //Case 1: Step+1 is odd,
                //Then diff + step+1 is even (odd + odd =even),return step+1
            //Case 2: Step+1 is even,
                //Then diff + step+1 + step+2 is even (odd + even + odd = even) return step +2
    
         
    int reachNumber(int target) {
        target=abs(target);

        int step =0;
        int totalSum = 0;
        while(target > totalSum){
            step++;
            totalSum += step;
        }

        if(target == totalSum){
            return step;
        } else {
            int difference = totalSum - target;
            if(difference % 2==0){
                return step;
            } else {
                // difference is odd
                if((step+1)%2==1){
                    return step +1;
                } else {
                    // step +1 is even
                    // step + 2 is odd
                    return step+2;
                }
            }
        }
    }
};
