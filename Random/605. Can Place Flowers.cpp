605. Can Place Flowers
Easy

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

class Solution {
public:
//     This is the logic the code is using-
// If there are count zeroes in between two 1s, then how many 1s can we place in those zeroes without violating the given condition? Answer is (count-1)/2. The only cases this doesn't apply are when there are zeroes(1 or more)

// At the beginning of the array.
// At the end of the array.
// For these 2 cases, the number of 1s that we can place is count/2. But to generalize the algorithm and to simplify code inside loop, count has been initialized to 1 for the first time and n-= (count-1)/2 effectively becomes n-= count/2 for the case 1. For case 2, result is updated outside the loop, again by count/2 times.

// Finally, we check if the number of possible 1s that we can place is greater than or equal to 0. If so, we return true else false.
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=1;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0)
            {
                count++;
            }
            else 
            {
                n=n-(count-1)/2;
                count=0;
            }
        }
        if(count!=0) n-=count/2;
        return n<=0;
       
    }
};
