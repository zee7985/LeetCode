78. Subsets
Medium

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]



class Solution {
public:
    //3 solution
    
//     //1.Bit masking
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> ans;
//         if(n==0){
//             return ans;
//         }
//         int range=1<<n;
//         for(int no=0;no<range;no++){
//             int i=0;
//             int j=no;
//             vector<int> temp;
//             while(j>0){
//                 if(j&1){
//                     temp.push_back(nums[i]);
//                 }
//                 i++;
//                 j=j>>1;
                
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
    
    //2.Recursion 
        vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        
        if (n == 0)
            return ans;
            
        sort(nums.begin(), nums.end());
        
        subsetRecusion(nums, ans, temp, 0);
        
        return ans;
    }
    
    void subsetRecusion(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int i)
    {
        if (i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        //there is no nums[i]
        subsetRecusion(nums, ans, temp, i+1);
        
        //there is nums[i]
        temp.push_back(nums[i]);
        subsetRecusion(nums, ans, temp, i+1);
    }
    
    
     //3. Similar to permutation
     void helper(vector<int>& nums, vector<vector<int>> &ans,vector<int>& c,int idx){
        // if(c.size() == nums.size()){
        ans.push_back(c);
            // return;
        // }
        for(int i = idx; i < nums.size(); i++){
            if(count(c.begin(), c.end(), nums[i]) == 0){
                c.push_back(nums[i]);
                helper(nums, ans,c,i+1);
                c.pop_back();
            }
        }
     }
         
         
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        
        if (n == 0)
            return ans;
            
        sort(nums.begin(), nums.end());
        
        helper(nums, ans, temp,0);
        
        return ans;
    }
        
  
};



