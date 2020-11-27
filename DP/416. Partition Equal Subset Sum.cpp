416. Partition Equal Subset Sum
Medium

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
class Solution {
public:
    
    bool helper(vector<int>&nums,int i,int total,vector<vector<int>>&dp)
    {
       if(total==0)
       {
           return true;
       }
        if(i==nums.size()-1 || total<0)
        {
            return false;
        }
        if(dp[i][total]!=-1)
        {
            return dp[i][total];
        }
        int ans=(helper(nums,i+1,total-nums[i],dp)|| helper(nums,i+1,total,dp));
        return dp[i][total]=ans;

    }
    
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto a:nums)
        {
            total+=a;
        }
        if(total%2!=0) return false;
        
        total/=2;
        int n=nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        return helper(nums,0,total,dp);
        
    }
};
