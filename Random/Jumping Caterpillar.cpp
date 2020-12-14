Jumping Caterpillars 

Given N leaves numbered from 1 to N . A caterpillar at leaf 1, jumps from leaf to leaf in multiples of Aj (Aj, 2Aj, 3Aj).
j is specific to the caterpillar. Whenever a caterpillar reaches a leaf, it eats it a little bit.. You have to find out how many leaves, from 1 to N, are left uneaten after all K caterpillars have reached the end. Each caterpillar has its own jump factor denoted by Aj, and each caterpillar starts at leaf number 1.

Input:
The first line consists of a integer T denoting the number of testcases. T test cases follow. Each test case consists of two lines of input. The first line consists of two integers: N, which denotes the number of leaves; and K, which denotes the number of caterpillars. Second line of each test case consists of K space seperated integers denoting the jumping factor of caterpillars.

Output:
For each testcase, in a new line, print a  single integer denoting the number of uneaten leaves.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= K <= 107
1 <= Aj <= 100

Example:
Input:
1
10 3
2 3 5
Output:
2

Explanation:
Testcase1: The leaves eaten by the first caterpillar are (2, 4, 6, 8, 10).
The leaves eaten by the second caterpilllar are (3, 6, 9)
The leaves eaten by the third caterpilllar are (5, 10)
Ultimately, the uneaten leaves are 1, 7 and their number is 2



#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    int arr[k]; //avoid using constant size
	    for(int i=0;i<k;i++)  //use 0 based indexing
	    cin>>arr[i];
	    bool prime[n+1];
	    memset(prime,true,sizeof(prime)); //use sizeof, its a better practice
	    int p;
	    for(int i=0;i<k;i++) //0 based index
	    {
	        p=arr[i];
	        if(prime[p]==true)
	        for(int i=p;i<=n;i=i+p)  //you have to consider the given elements too, so not 2*p
	        prime[i]=false;         //p stays constant here, it should be i
	    }
	    int cnt=0;
	    for(int i=1;i<=n;i++)    
	    if(prime[i]==true)
	    cnt++;
	    cout<<cnt<<endl;
	    
	}
	return 0;
}
