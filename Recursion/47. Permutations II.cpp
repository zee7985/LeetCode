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
    
    
    //3.
    
    I prefer to use the unordered_map to solve the dup problem. How does it solve the problem? because it treats all the dup as one element with several copies.

    For example, [1, 1, 2], when you iterate, in the same "level", the 1 will only be put once. We only put the other 1 into the vector in the recursive call in next levels.

    class Solution {
        void helper(unordered_map<int, int>& bar, vector<int>& temp, vector<vector<int>>& res, int n){
        if(temp.size() == n){
            res.push_back(temp);
            return ;
        }
        for(auto &i : bar){
            if(i.second <= 0) continue;
            i.second --;
            temp.push_back(i.first);
            helper(bar, temp, res, n);
            temp.pop_back();
            i.second ++;
        }
    }
    
    public:
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> res;
          unordered_map<int, int> bar;
          for(int i : nums){
              bar[i] ++;
          }
          vector<int> temp;
          helper(bar, temp, res, nums.size());
          return res;
    }
};


