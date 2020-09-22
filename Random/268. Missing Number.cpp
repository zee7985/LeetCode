268. Missing Number
Easy


Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

class Solution {
public:
    //1. Sort -O(nlogn + n) ,O(1) space
    
    //2.Hashing O(n) and O(n) space
    
    
    //3.Xor  O(n) and O(1)
    int missingNumber(vector<int>& nums) {
        
        int no=nums.size();   // no equal to n because we will loop less than n
        for(int i=0;i<nums.size();i++)
        {
            no^=i^nums[i];
        }
        
        return no;
    }
    
    //4. 0(n) and o(1)   //may lead to overflow   sum+=i-nums[i];
    // int missingNumber(vector<int> &nums)
    // {
    //     int n=nums.size();
    //     int sum=n*(n+1)/2;
    //     int actSum=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         actSum+=nums[i];
    //     }
    //     return sum-actSum;
    // }
    
    
};
