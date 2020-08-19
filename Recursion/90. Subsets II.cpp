90. Subsets II
Medium

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

class Solution {
public:
   void helper(vector<int>& nums, vector<vector<int>> &ans,vector<int>& c,int idx){
    
        ans.push_back(c);
 
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            
            c.push_back(nums[i]);
            helper(nums, ans,c,i+1);
            c.pop_back();

        }
     }
         
         
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        
            
        sort(nums.begin(), nums.end());
        
        helper(nums, ans, temp,0);
        
        return ans;
    }
};
