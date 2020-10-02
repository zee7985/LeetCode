128. Longest Consecutive Sequence
Hard


Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    // //1. O(nlogn)
    //     if(nums.size()==0) return 0;
    //     sort(nums.begin(),nums.end());
    //     int ans=1;
    //     int count=1;
    //     for(int i=1;i<nums.size();i++)
    //     {
    //         if(nums[i]==nums[i-1]) continue;  // if prev elemnt same eg- 0,1,1,2 ans =3 (not 2)
    //         if(nums[i]==(nums[i-1]+1))
    //         {
    //             count++;
    //             ans=max(ans,count);
    //         }
    //         else
    //         {
    //             count=1;
    //         }
    //     }
    //     return ans;
    // }
    
    
    //2.O(3n) 
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto a: nums)
        {
            s.insert(a);
        }
        
        int longAns=0;
        for(auto num: s)
        {
            if(s.find(num-1)==s.end())       // If no lower value(i.e 1 less than curr value) present ,then it is the starting point of sequence
            {
                int currNum=num;
                int currMax=1;
                while(s.find(currNum+1)!=s.end())   //this while loop will run atmost n times in all the iterations ,thats why complexity o(n)
                {
                    currNum+=1;
                    currMax+=1;
                }
                longAns=max(longAns,currMax);
            }
            
        }
        return longAns;
    }
};
        
