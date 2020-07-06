39. Combination Sum
Medium


Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]


class Solution {
public:
    vector<vector<int>> ans;
    void helper_coin(vector<int>& candidates,int idx,int sum, int target,vector<int> c) 
        {
         
            if(idx==candidates.size() || sum==target){
                if(sum==target)
                {
                    ans.push_back(c);
                }
            }
            
            for(int i=idx;i<candidates.size();i++){
                if(sum+candidates[i]<=target)
                {
                    c.push_back(candidates[i]);
                    helper_coin(candidates,i,sum+candidates[i],target,c);
                    c.pop_back();
                }
            }
        }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> c;
        helper_coin(candidates,0,0,target,c);
        return ans;
    }
};