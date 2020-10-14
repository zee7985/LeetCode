213. House Robber II
Medium


You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0

// This problem is a little tricky at first glance. However, it is just a variation of House Robber problem, this problem can simply be decomposed into two House Robber problems.
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

// Rob houses 0 to n - 2;
// Rob houses 1 to n - 1.
// The code is as follows. Some edge cases (n < 2) are handled explicitly.

class Solution {
public:
    int helper(vector<int>& nums,int i,int n,vector<int> &dp)
    {
        // if(i>=nums.size())
        if(i>=n)
        {
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
         
        int robcurr=helper(nums,i+2,n,dp)+nums[i];
        int dontRob=helper(nums,i+1,n,dp);
                
        return dp[i]=max(robcurr,dontRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        if (n ==1) return nums[0];
        
        return max(helper(nums, 0, n - 1,dp1), helper(nums, 1, n ,dp2));
    }
};
