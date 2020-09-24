31. Next Permutation
Medium

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

class Solution {
public:
    //1. use inbuilt
    
    //2. Generate all the permutations
    
    //3.As there will be always increasing sequence,so
    // A. Find the largest index k such that nums[k] < nums[k + 1]. If no such index , just reverse (eg-1 3 5 4 2) -> k=1(index) because ele 3 is breakpt
    // B. Find the largest index l > k such that nums[k] < nums[l] -> (k=3)because 4 is just greater than 3
    // C. Swap nums[k] and nums[l]  ->(1 4 5 3 2)
    // D. Reverse the sub-array nums[k + 1:]  -> (1 4 2 3 5)Answer
    
    // how to understand it:
    // step-1: find the first digit that can be swapped to make permutation bigger
    // step-2: find the digit bigger but closest to nums[k]
    // step-3: swap(nums[k], nums[l])
    // step-4: sort the subarray nums[k+1:end], why we can just reverse instead of sort?
    //   because we know nums[k+1:end] must be non-increasing, reason:
    //   1. at step 1, we know nums[k+1:end] is non-decreasing
    //   2. before swap in step 3, we know nums[l-1] >= nums[l] > nums[k] >=nums[l+1]
    //   3. so after swap, we still have nums[l-1] > nums[k] >= nums[l+1], so we can reverse it
    
    void nextPermutation(vector<int>& nums) {
        int idx1=-1,idx2=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx1=i;
                break;
            }
        }
        
        if(idx1<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>idx1;i--)
            {
                if(nums[i]>nums[idx1])
                {
                    idx2=i;
                    break;
                }
            }
            swap(nums[idx1],nums[idx2]);
            reverse(nums.begin()+idx1 + 1,nums.end());
        
        }
        
    }
};
