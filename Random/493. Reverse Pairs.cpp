493. Reverse Pairs
Hard

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.

class Solution {
public:
    
    //1.o(n^2)
    
    //2.mergeSort
    //Similar to inversion count 
    //we first count all the pair satisfying the condition and then merge
    // For example,
    // left: 4 6 8 right: 1 2 3
    // so we use two pointers to travel left and right parts. For each leftPart[i], if j<=e && nums[i] > 2*nums[j], 
    //we just continue to move j to  the end, to increase rightPart[j], until it is valid. Like in our example, 
    //left's 4 can match 1 and 2; left's 6 can match 1, 2, 3, and left's 8     can match 1, 2, 3. So in this particular round,
    //there are 8 pairs found, so we increases our total by 8.
    
    
    //https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18
    
    int merge(int s,int mid,int e,vector<int> &nums)
    {
        int count=0;
        int j=mid+1;
        for(int i=s;i<=mid;i++)
        {
            while(j<=e && nums[i] > 2LL*nums[j])    //now check the condition ,if true increment j
            {
                j++;
            }
            count+=(j-(mid+1));
        }
        
        vector<int> temp;
        int i=s;
        j=mid+1;
        while(i<=mid && j<=e)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else temp.push_back(nums[j++]);
        }
        
        while(i<=mid) 
        {
            temp.push_back(nums[i++]);
        }
    
        while(j<=e)
        {
            temp.push_back(nums[j++]);
        }
       
        for(int i=s;i<=e;++i) {
            nums[i]=temp[i-s];
        }
        return count;
    }
    
    int mergesort(int s,int e,vector<int> &nums)
    {
        if(s>=e) return 0;
        int count=0;
        int mid=s+(e-s)/2;
        count+=mergesort(s,mid,nums);
        count+=mergesort(mid+1,e,nums);
        count+=merge(s,mid,e,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};
