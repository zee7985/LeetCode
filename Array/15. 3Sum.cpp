15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(), a.end());
        
        int j;
        int k;
 
        for(int i=0;i<n;)
        {
            k=i+1;
            j=n-1;
            while(k<j)
            {
                if (a[j] + a[k] +a[i]  == 0)
                {
                
                    ans.push_back(vector<int>{a[i], a[k], a[j]});
                    k++;
                    j--;
                    while (k<j && a[k] == a[k - 1])  k++;   // Processing duplicates of Number 2
                    while (k<j && a[j] == a[j + 1]) j--;   // Processing duplicates of Number 3
                    
                    
                }
                else if(a[j] + a[i] + a[k]> 0)
                { 
                    j--;
                    while (k<j && a[j] == a[j + 1]) j--;       // k<j -to avoid overflow
                }
                else{
                    k++;
                    while (k<j && a[k] == a[k - 1])  k++;
                }
            }
            i++;
            while((i < n) && a[i] == a[i-1])   //// Processing duplicates of Number 1
                i++;
        }
        return ans;
    }
};

