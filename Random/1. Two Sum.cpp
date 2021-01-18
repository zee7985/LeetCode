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

//================================================================
2-Variation of 2sum

Pairs of Songs With Total Durations Divisible by 60

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500
	
class Solution {
public:
    //Similar to two sum
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        map<int,int> mp;
        for(auto t:time)
        {
            if(t%60==0)
            {
                ans+=mp[0];
            }
            else if(mp.find(60-t%60)!=mp.end())
            {
                ans+=mp[60- t%60];
                
            }
            mp[t%60]++;
            
        }
        return ans;
    }
};

//==================================================================================

1679. Max Number of K-Sum Pairs
Medium

You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.

 Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //Two pointer -NLOGN
    //     sort(nums.begin(),nums.end());
    //     int i=0;
    //     int j=nums.size()-1;
    //     int count=0;
    //     while(i<j)
    //     {
    //         if(nums[i]+nums[j]==k)
    //         {
    //             count++;
    //             i++;
    //             j--;
    //         }
    //         else if(nums[i]+nums[j]<k)
    //         {
    //             i++;
    //         }
    //         else if(nums[i]+nums[j]>k)
    //         {
    //             j--;
    //         }
    //     }
    //     return count;
    // }
        
        //O(n) 2Sum
        map<int,int> mp;
        
        
        int count=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(k-nums[i])!=mp.end())
            {
                count++;
                mp[k-nums[i]]--;
                if(mp[k-nums[i]]==0)// Delete when count become zero because it will be add to our ans(if not deleted)
                {
                    mp.erase(k-nums[i]);
                }
            }
            else 
                mp[nums[i]]++;
        }
       return count;
    }
     
    
};
