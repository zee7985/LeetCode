75. Sort Colors
Medium

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]

class Solution {
public:
    //1.Sort o(nlogn)
    
    //2.Counting Sort
    // two pass O(m+n) space
//     void sortColors(int A[], int n) {
//     int num0 = 0, num1 = 0, num2 = 0;
    
//     for(int i = 0; i < n; i++) {
//         if (A[i] == 0) ++num0;
//         else if (A[i] == 1) ++num1;
//         else if (A[i] == 2) ++num2;
//     }
    
//     for(int i = 0; i < num0; ++i) A[i] = 0;
//     for(int i = 0; i < num1; ++i) A[num0+i] = 1;
//     for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
//     }
    
    //3.using 3 pointer low and mid at start and high at end
    void sortColors(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high--]);
            }
        }
        
        
    }
    
};
