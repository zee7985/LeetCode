368. Largest Divisible Subset
Medium

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

// 1. Sort all array elements in increasing order. The purpose of sorting is to make sure that all divisors of an element appear before it.
// 2. Create an array dp[] of same size as input array. dp[i] stores size of divisible subset ending with arr[i] (In sorted array). The minimum value of dp[i] would be 1 .Traverse all array elements. For every element, find a divisor arr[j] with largest value of dp[j] and store the value of dp[i] as dp[j] + 1.(Simply LIS)
// 3.Find the subset 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        if(n==0)
            return ans;
        
        sort(nums.begin(),nums.end());
        int max = 1;
        vector<int> dp(n+1,1);
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                    if(max<dp[i])
                        max = dp[i];
                }
            }
        }
        //Now push the answer LIS
        int prev = -1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==max  && (prev%nums[i]==0 || prev==-1))  //if prev=-1 ,then it is last element ,directly push in vector else check if it divides 
            {                                                 // previous element
                ans.push_back(nums[i]);
                max --;                                       // decrement max by 1
                prev = nums[i];           //make prev equal to current element
            }
        }
        return ans;
    }
};
