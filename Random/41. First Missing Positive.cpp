41. First Missing Positive
Hard


Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.

class Solution {
public:
    //1.O(nlogn) -sort and then check
    //2.Freq Array o(n)space
    
    //3.Swap o(n) with o(1) space 
    //Notice, that first missinig positive will always be in range 1,2,...n,n+1, where n is length of nums.
    //Let us rearrange numbers, putting each number on its place: number i on place i-1 (because indexes start          with 0):and ignore duplicate number and number greater than arr length

    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]-1])  //ignore duplicate,negative and no.> arr.size
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
                return i+1;
            }
        }
        return n+1;   // input : 1,2,3  output : 4
    }
};
