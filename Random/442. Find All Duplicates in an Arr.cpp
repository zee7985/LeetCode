442. Find All Duplicates in an Array
Medium


Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

class Solution {
public:
    //1. MAp O(n) with o(n) space
    
    //2.similar to finding first positive integer-o(n) with o(1) space
    // Here we place the element to its corrct position and check if it is equal to current index in second pass
    //if not it is the ans
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int> v;
        while(i<n)
        {
            if(nums[i]!=nums[nums[i]-1])  //ignore duplicate
            {
                swap(nums[i],nums[nums[i]-1]);
            }
            else
            {
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                v.push_back(nums[i]);
            }
        }
        return v;        
    }
    
    //3. o(n) with o(1) space
    //The number that appears twice tries to turn back the number at that 
    //index to +ve while all others remain -ve.

    vector<int> findDuplicates(vector<int>& nums) 
    {
        int idx = 0, size = nums.size();
        vector<int> res;

        for (int i = 0; i < size; i++)
        {
            idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                res.push_back(idx+1);
        }

        return res;
    }

};



