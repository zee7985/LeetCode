525. Contiguous Array
Medium


Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

HInt:The logic used here is when we encounter 1 we add 1 to the prefix sum and when we encounter 0
         we add -1 to the prefix sum. We store all the prefix sum in a map and if we encounter a prefix sum 
        which was discovered earlier that means between last occurence of that sum and this occurance we
        have equal number of '+1s' and '-1s' which is the problem statement that we need equal number of 1s 
        and 0s. We take the maximum of all.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        
        int ans = 0, sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i]?1:-1;  /*nums[i] == 1 , count++; nums[i] == 0, count--*/
            if(sum==0){
                ans=max(ans,i+1);
            }
            if (mp.find(sum)!=mp.end()){
                ans = max(ans, i-mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        
        return ans;
    }
        
};