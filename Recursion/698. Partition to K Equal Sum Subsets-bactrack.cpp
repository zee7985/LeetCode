698. Partition to K Equal Sum Subsets
Medium

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets
 whose sums are all equal.

 Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.


class Solution {
public:
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0 ;
        for( int nu : nums)
        {
            sum += nu;
        }
        if( sum % k !=0 || k==0) return false;    //k(bucket)
        
        vector<int>visited( n , 0);
        return helper_k( nums , visited,0 , k , 0,sum/k);
        
    }
   bool helper_k( vector<int>&nums,vector<int> &visited,int idx , int k , int sum,int target)
   {  
       if(k==1){             // bucket size is 1 ,then we will stop here because it will definately filled with target sum
           return true;
       }
        if(sum==target ){                               //this condition means you have found one suset so start from begining for another subset
            return helper_k(nums,visited,0,k-1,0,target);      // if sum ==target ,then reduce the bucket size by 1
        }
    
       for(int i = idx ; i < nums.size() ; i++)
       {
           if(!visited[i] && sum+nums[i]<=target){
               visited[i]=1;
               if(helper_k(nums,visited,i+1,k,sum+nums[i],target)){
                   return true;
               }
               visited[i]=0;                                      // backtrack 
           }
       }
    return false;
    }
    
};

