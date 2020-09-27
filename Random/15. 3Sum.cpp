15. 3Sum
Medium
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        int i=0;
        while(i<n-2)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[i] + nums[j] +nums[k]==0)
                {
                    ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(k>j && nums[j]==nums[j-1]) j++;
                    while(k>j && nums[k]==nums[k+1]) k--;

                }
                else if(nums[i] + nums[j] +nums[k]>0)
                {
                    k--;
                    while(k>j && nums[k]==nums[k+1]) k--;
                }
                else
                {
                    j++;
                    while(k>j && nums[j]==nums[j-1]) j++;

                }
            }
            i++;
            while(i<n-2 && nums[i]==nums[i-1]) i++;
        }
        return ans;
        
    }
};
