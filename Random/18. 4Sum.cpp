18. 4Sum
Medium
re
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(), a.end());
        
        int j;
        int k;
 
        for(int i=0;i<n-3;)
        {
            // if ((i>0) && (a[i]==a[i-1]))   //// Processing duplicates of Number 1
            //     continue;
            for(int l=i+1;l<n-2;)
            {
                // if ((l>i) && (a[l]==a[l-1]))   //// Processing duplicates of Number 2
                //     continue;
                
                k=l+1;
                j=n-1;
                while(k<j)
                {
                    if (a[j] + a[k] +a[i] +a[l] == target)
                    {
                
                        ans.push_back(vector<int>{a[i],a[l], a[k], a[j]});
                        k++;
                        j--;
                        while (k<j && a[k] == a[k - 1])  k++;   // Processing duplicates of Number 3
                        while (k<j && a[j] == a[j + 1]) j--;   // Processing duplicates of Number 4
                    
                    
                    }
                    else if(a[j] + a[i] + a[k] + a[l]> target)
                    { 
                        j--;
                        while (k<j && a[j] == a[j + 1]) j--;       // k<j -to avoid overflow
                    }
                    else{
                        k++;
                        while (k<j && a[k] == a[k - 1])  k++;
                    }
                }
                l++;
                while((l < n) && a[l] == a[l-1])
                l++;
            }
             i++;
            while((i < n) && a[i] == a[i-1])
            i++;
        }
        return ans;
    }
};


