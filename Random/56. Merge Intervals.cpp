56. Merge Intervals
Medium

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        {
            return {};
        }
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> temp=intervals[0];  //store the first interval  temp=(1,3)
        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<=temp[1])   //overlaping intervals
            {
                temp[1]=max(temp[1],intervals[i][1]);    // store the max eg [1,3],[2,6]  temp[0]=1,temp[1]=max(3,6);
            }
            else
            {
                ans.push_back(temp);
                temp=intervals[i];   // now make temp vector to current pair ,temp=(2,6)
            }
        }
        ans.push_back(temp);        //push the last intrval
        return ans;
    }
  
};
