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



//2.Length of Largest Subarray with zero sum

Given an array of integers, find the length of the longest sub-array with sum equals to 0.
Examples :

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation:There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with 
elements summing up-to 0 is {0}


//A.Naive Approach o(n^2) 
int maxLen(int arr[], int n) 
{ 
    int max_len = 0; // Initialize result 
  
    // Pick a starting point 
    for (int i = 0; i < n; i++) { 
        // Initialize currr_sum for every starting point 
        int curr_sum = 0; 
  
        // try all subarrays starting with 'i' 
        for (int j = i; j < n; j++) { 
            curr_sum += arr[j]; 
  
            // If curr_sum becomes 0, then update max_len 
            // if required 
            if (curr_sum == 0) 
                max_len = max(max_len, j - i + 1); 
        } 
    } 
    return max_len; 
} 

//2. o(n) or o(nlogn)n-> worst case in map
   int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        
        int ans = 0, sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];
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
        
