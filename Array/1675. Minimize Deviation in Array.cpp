1675. Minimize Deviation in Array
Hard


You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3
 

Constraints:

n == nums.length
2 <= n <= 105
1 <= nums[i] <= 109

class Solution {
public:
    //We have two types of operations: double odd numbers, and halve even numbers. We can try to sort all               numbers,and increase the smallest number (if it's odd) and decrease the largest number (if it's even). This       can getquite complicated.

    //Intuition 1: we can divide even numbers multiple times - till we get an odd number, but we can only double       odd numbers once. After that, it will become an even number.

    //Intuition 2: Even numbers never increase.

    //Flip: we can double all odd numbers first, so we can get forget of the second operation. Now, we only need       to decrease the largest number - while it's even, which results a very simple solution.

    //Solution
    //Double odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum             difference between the top of the heap and the smallest number. While the top of the heap is even, remove        it,divide, and put back to the heap.
    
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        
        int mini=INT_MAX;
        for(int i : nums)
        {
            if(i%2!=0)
            {
                i=i*2;
            }
            mini=min(mini,i);
            pq.push(i);
        }
        
        int diff=INT_MAX;
        while(pq.top()%2==0)          // Till the largest no is odd - Because we can only double odd number
        {
            int largest=pq.top(); pq.pop();
            diff=min(diff,largest-mini);
            
            mini=min(mini,largest/2); // Update mini
            pq.push(largest/2);
        }
        
        return min(diff,pq.top()-mini);
    }
};
