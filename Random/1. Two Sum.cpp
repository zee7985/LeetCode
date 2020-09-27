1. Two Sum
Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 105
-109 <= nums[i] <= 109
-109 <= target <


class Solution {
public:
    //1. 0(n^2)
    //2 Two pointer nlog(n) with  o(1) space
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int,int> > v;
    
//         for(int i = 0; i < nums.size(); i++)
//             v.push_back({nums[i],i});
    
    
//         sort(v.begin(), v.end());
    
        
//         int i = 0, j = v.size() - 1;
    
//         while(i< j){
//             if(v[i].first + v[j].first == target)
//                 return {v[i].second, v[j].second};
        
    
//             if(v[i].first + v[j].first > target)
//                 j--;
        
        
//             else
//                 i++;
//         }
    
//         return {-1,-1};
	
//     }
    
    //3.MAp o(n)  with o(n) space
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target - nums[i])!=mp.end())
            {
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
    return {-1,-1};
    }
};
