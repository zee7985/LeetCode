229. Majority Element II
Medium

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

class Solution {
public:
    //o(n) with o(n)space)
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> v;
//         map<int,int> mp;
//         int n=nums.size();
//         n=n/3;
//         for(auto a:nums)
//         {
//             mp[a]++;
//         }
        
//         for(auto i: mp)
//         {
//             if(i.second > n)
//             {
//                 v.push_back(i.first);
//             }
//         }
//         return v;
//     }
    
    //2. Boyer Moore Voting 
    
//     So, taking the idea from the basic problem we can extend it to find majority elements that appear more than n/3 times.
// In this case, first we nneed to understand that there will be atmost 2 MAJORITY ELEMENT. This is pretty self explainatory 
  //  if you read the question carefully.

// Okay, so just like we did in the simpler version of the problem, we take two elements as the majority element and maintain their
        // frequency counts and once we find an element that differs from the two, we decrement both the elements' counts. 
        // In this case we have to look for triplets instead of pairs. This essentially means that we form a triplet out of
        //     2 majority and one non-majority element and remove them from the array. We repeat the process till we consider 
        //     all array elements and simply verify if the elements we found are correct or not, which can be done in a single pass.

// Time Complexity: O(n)
// Space Complexity: O(1)


    vector<int> majorityElement(vector<int>& nums) 
    {
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }    
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        //check that our ans is correct or not 
        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz/3)
            ans.push_back(num1);
        if (count2 > sz/3)
            ans.push_back(num2);
        return ans;
    }
};
