47. Permutations II
Medium

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

class Solution {
public:
   
//     void DFS(vector<vector<int>>& res, vector<int> nums, int pos){
//         if(pos == nums.size() - 1){
//             res.push_back(nums);
//             return;
//         }
//         for(int i = pos; i < nums.size(); i++){
//             if(nums[i]==nums[pos] && i!=pos) continue;   // Dont swap the same no.s  because it will result in same no
//             swap(nums[pos], nums[i]);
//             DFS(res, nums, pos + 1);
//            // swap(nums[pos], nums[i]);
//         }
//     }


//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>>res;
//         sort(nums.begin(),nums.end());
//          DFS(res, nums, 0);
//          return res;   
        
//     }
    
    
    //2.
    
     vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int>& c,vector<bool> visited){
        if(c.size() == nums.size()){
            ans.push_back(c);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])) continue;
            
            visited[i]=true;
            c.push_back(nums[i]);
            helper(nums, c,visited);
            c.pop_back();
            visited[i]=false;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> c;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        helper(nums, c,visited);
        
        return ans;
    }
};


