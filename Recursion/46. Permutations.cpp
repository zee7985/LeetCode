46. Permutations
Medium
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    
    vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int>& c){
        if(c.size() == nums.size()){
            ans.push_back(c);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(count(c.begin(), c.end(), nums[i]) == 0){
                c.push_back(nums[i]);
                helper(nums, c);
                c.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> c;
        helper(nums, c);
        return ans;
    }
};

    
    
   // 2.Swap Function
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>res;
//         DFS(res, nums, 0);
//         return res;        
//     }
    
//     void DFS(vector<vector<int>>& res, vector<int> nums, int pos){
//         if(pos == nums.size() - 1){
//             res.push_back(nums);
//             return;
//         }
//         for(int i = pos; i < nums.size(); i++){
//             swap(nums[pos], nums[i]);
//             DFS(res, nums, pos + 1);
//            // swap(nums[pos], nums[i]);
//         }
//     }
    
// };

//2.Inbuilt Function
 // class Solution {
 //    public:
 //     vector<vector<int>> permute(vector<int>& nums) {
 //        vector<vector<int> > ans;
 //        sort(nums.begin(),nums.end());
 //        ans.push_back(nums);
 //        while(next_permutation(nums.begin(),nums.end())) { 
 //            ans.push_back(nums);
 //        }
 //        return ans;
 //    }
 // };
