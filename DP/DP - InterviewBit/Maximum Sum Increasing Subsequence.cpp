Maximum Sum Increasing Subsequence
Difficulty Level : Medium

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of 
the given array such that the integers in the subsequence are sorted in increasing order. 
For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10
 
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n+1,0);
	    dp[0]=arr[0];
	    int maxAns=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        int max_=0;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j])
	            {
	               max_=max(max_,dp[j]);   // find the maximum of all the cumulative sum is condition satisfy
	            }
	        }
	        if(max_==0) dp[i]=arr[i];     // If there is no smaller element, add only current element
	        else dp[i]= max_ + arr[i];    // Else add max upto current i + currEle
	        
	        maxAns=max(maxAns,dp[i]);
	    }
	    return maxAns;
	}  
