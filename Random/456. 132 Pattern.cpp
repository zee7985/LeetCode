456. 132 Pattern
Medium

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 104
-109 <= nums[i] <= 109


class Solution {
public:
    //1.o(n^3)
    // bool find132pattern(vector<int>& nums) {
    //     int n=nums.size();
    //    for(int i=0;i<n-2;i++)
    //    {
    //        for(int j=i+1;j<n-1;j++)
    //        {
    //            for(int k=j+1;k<n;k++)
    //            {
    //                if(nums[i]< nums[k]  && nums[k]<nums[j])
    //                {
    //                    return true;
    //                }
    //            }
    //        }
    //    }
    //     return false;
    // }
    
    //2. optimized brute force-o(n^2)
    // bool find132pattern(vector<int>& nums) {
    //     int n=nums.size();
    //     int firstMin=INT_MAX;
    //    for(int j=0;j<n-1;j++)
    //    {
    //        firstMin=min(firstMin,nums[j]);
    //        for(int k=j+1;k<n;k++)
    //        {
    //            if( firstMin < nums[k]  && nums[k]<nums[j])
    //             {
    //                  return true;
    //             }
    //         }
    //    }
    //     return false;
    // }
    
    
    
    //3. using stack -o(n)
    bool find132pattern(vector<int>& nums) {
         stack<int> st;
         int n=nums.size();
        vector<int> minArr(n);
        minArr[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            minArr[i]=min(minArr[i-1],nums[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>minArr[i])
            {
                while(!st.empty() && st.top()<= minArr[i])
                {
                    st.top();st.pop();
                }
                if(!st.empty() && st.top()<nums[i])
                {
                    return true;
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
    

};
