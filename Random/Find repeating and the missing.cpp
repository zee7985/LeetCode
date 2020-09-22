//https://ide.codingblocks.com/s/341477

// Find the repeating and the missing

// Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.
// Examples:

 
// Input: arr[] = {3, 1, 3}
// Output: Missing = 2, Repeating = 3
// Explanation: In the array, 
// 2 is missing and 3 occurs twice 

// Input: arr[] = {4, 3, 6, 2, 1, 1}
// Output: Missing = 5, Repeating = 1

#include <bits/stdc++.h>
using namespace std;


//1.sort O(nlogn)
//2.Hashing o(n) witth o(n) space


//3.
//  (Make two equations using sum and sum of squares)
// Approach:

// Let x be the missing and y be the repeating element.
// Let N is the size of array.
// Get the sum of all numbers using formula S = N(N+1)/2
// Get product of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
// Iterate through a loop from i=1….N
// S -= A[i]
// Sum_Sq -= (A[i]*A[i])
// It will give two equations
// x-y = S – (1)
// x^2 – y^2 = Sum_sq
// x+ y = (Sum_sq/S) – (2)

// Time Complexity: O(n) with o(1) space

#define ll long long

void solve(){
	ll n;
    cin>>n;
    ll arr[n],sum=(n*(n+1))/2,sumsq=(n*(n+1)*(2*n+1))/6;
    for(ll i=0;i<n;i++) cin>>arr[i];
    for(ll i=0;i<n;i++){
        sum-=arr[i];
        sumsq-=arr[i]*arr[i];
    }
    ll x,y;

    x=(sumsq + sum)/sum)/2;
    y=x-sum;
    cout<<"missing: "<<x<<" repeating: "<<y<<endl;
	return;
}
int main(){
    int t=1,z=1;
    // scanf("%d",&t);
    while(z<=t){
        solve(); z++;
    }
    return 0;
}


//4. (Use XOR)
// Approach:

// Let x and y be the desired output elements.
// Calculate XOR of all the array elements.
// xor1 = arr[0]^arr[1]^arr[2]…..arr[n-1]

// XOR the result with all numbers from 1 to n
// xor1 = xor1^1^2^…..^n

// In the result xor1, all elements would nullify each other except x and y.
//  All the bits that are set in xor1 will be set in either x or y. So if we take any set
//   bit (We have chosen the rightmost set bit in code) of xor1 and divide the elements of the
//    array in two sets – one set of elements with same bit set and other set with same bit not
//     set. By doing so, we will get x in one set and y in another set. Now if we do XOR of all
//      the elements in first set, we will get x, and by doing same in other set we will get y..

void getTwoElements(vector<int> arr, int n) 
{ 
    
    int xor1; 
  
    
    int set_bit_no; 
  
    int i; 
    int x = 0; 
    int y= 0; 
  
    xor1 = arr[0]; 
  
    for (i = 1; i < n; i++) 
        xor1 = xor1 ^ arr[i]; 
  
    for (i = 1; i <= n; i++) 
        xor1 = xor1 ^ i; 
  
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1); 
  
    for (i = 0; i < n; i++) { 
        if (arr[i] & set_bit_no) 
            /* arr[i] belongs to first set */
            x = x ^ arr[i]; 
  
        else
            /* arr[i] belongs to second set*/
            y= y^ arr[i]; 
    } 
    for (i = 1; i <= n; i++) { 
        if (i & set_bit_no) 
            /* i belongs to first set */
            x = x ^ i; 
  
        else
            /* i belongs to second set*/
            y= y^ i; 
    } 
    cout<<x<<" "<<y;
    
} 
  

int main() 
{ 
    int n;
    cin>>n;
    vetcor<int>arr= { 1, 3, 4, 5, 5, 6, 2 };
  
    getTwoElements(arr, n);  
} 
