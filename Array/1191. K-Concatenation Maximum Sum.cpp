1191. K-Concatenation Maximum Sum
Medium


Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0



class Solution {
public:
    //Divide array in two parts of Size 2*Arr and k-2*Array
    //Find maxSubarray sum of 2*Arr(if k>=2)
     int kConcatenationMaxSum(vector<int>& arr, int k)
    { 
        long max_ending_here = arr[0] > 0 ? arr[0] : 0,max_so_far = max_ending_here;
        long long int n=arr.size();
        
        for (long long i = 1; i < min(k,2)*n; i++)  //Find maxSubarray sum of
        {                                             // 2*Arr(if k>=2)
        max_ending_here = max_ending_here + arr[i%n]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here%1000000007; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    }
         
    long long int sum=0;
    for(long long int i=0;i<n;i++){  //Find Out sum of array for (k-2)*Arr
        sum+=arr[i];
    }
    if(sum>0 && k>2){
        long long int ans=(max_so_far +(k-2)*sum)%1000000007;//If sum>0 ,then add                                                                        // maxSubArraysum and k-2*sum
        return ans;
    }
    else{
        return (max_so_far)%1000000007;
    } 
    } 
};

//TLE-36/38 testcase passed
// int kConcatenationMaxSum(vector<int>& arr, int k)
//     { 
//         long max_ending_here = arr[0] > 0 ? arr[0] : 0,max_so_far = max_ending_here;
//         long long int n=arr.size();
//         for (long long i = 1; i < n*k; i++) 
//         { 
//         max_ending_here = max_ending_here + arr[i%n]; 
//         if (max_so_far < max_ending_here) 
//             max_so_far = max_ending_here%100000007; 
  
//         if (max_ending_here < 0) 
//             max_ending_here = 0; 
//     } 
//     return max_so_far%100000007; 
// } 