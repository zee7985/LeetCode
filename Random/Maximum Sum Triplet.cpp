Maximum Sum Triplet
Asked in:  
Directi
Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1: 16
Output 2: 6
Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
 
 //O(n^2) solution
// int Solution::solve(vector<int> &A) {
//     int n=A.size();
    
//     int ans = 0;
 
//     for (int i = 1; i < n - 1; ++i) {
//         int max1 = 0, max2 = 0;
 
//         for (int j = 0; j < i; ++j)
//             if (A[j] < A[i])
//                 max1 = max(max1, A[j]);
 
    
//         for (int j = i + 1; j < n; ++j)
//             if (A[j] > A[i])
//                 max2 = max(max2, A[j]);
 
//         if(max1 && max2)
//              ans=max(ans,max1+A[i]+max2);
//     }
//     return ans;
// }

//0(nlogn)
// Best and efficient approach is use the concept of maximum suffix-array and binary search. 

// For finding maximum number greater number greater than given number beyond it, we can
// maintain a maximum suffix-array array such that for any number(suffixi) it would contain
// maximum number from index i, i+1, … n-1. Suffix array can be calculated in O(n) time.
// For finding maximum number smaller than the given number preceding it, we can maintain
// a sorted list of numbers before a given number such we can simply perform a binary search
// to find a number which is just smaller than the given number. In C++ language, we can
// perform this by using set associative container of STL library. 
int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> rightMax(n);
    rightMax[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i]=max(rightMax[i+1],A[i]);
    }
    
    set<int> s;
    s.insert(A[0]);
    int ans=0;
    
    for(int i=1;i<n-1;i++)
    {
        s.insert(A[i]);
        int Ak=rightMax[i+1];
        int Aj=A[i];
        
        if(Aj<Ak)
        {
            auto it=s.lower_bound(A[i]); // We can also use lowerbound
            // auto it=s.find(A[i]);  //Need to find just smaller number than Aj
            it--;                  // Since 'lower_bound' returns the first iterator 
                                    // greater than 'n', thus we have to decrement the
                                    //pointer for getting the minimum value
            ans=max(ans,*it +Aj +Ak);
        }
        
    }
    return ans;
}

