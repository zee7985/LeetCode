Print All Paths With Target Sum Subset
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add up to "tar" or not.
5. Also, you have to print the indices of elements that should be selected to achieve the given target.
6. You have to print all such configurations.


Sample Input
5
4 2 7 1 3
10

Sample Output
true
2 4 
1 2 3 
0 1 3 4 

//  DP Table -somewhere similar to knapsack

#include <bits/stdc++.h>
using namespace std;


class Pair {
    public:
    string psf;
    int i;
    int j;

    Pair(string psf, int i, int j) {
        this->psf = psf;
        this->i = i;
        this->j = j;
    }
};

int main()
{
    int n,target;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
        
    }
    cin>>target;

    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=target;j++) {
            if(j==0)                    //First column will be always true because we dont need any element for target 0
            {
                dp[i][j]=true;
            }
            else if (i==0) {           // First row will be always false because there will no element to make target[i]
                dp[i][j] = false;
            }
            else
            {
                dp[i][j]=dp[i-1][j];                  // Excluding current element -store previous ans 
                if(j-arr[i-1]>=0)                    // Check if after including current element ,there is ans possible at idx (j-arr[i]) 
                {
                    if(dp[i-1][j-arr[i-1]]==true)
                    {
                        dp[i][j]=true;
                    }
                }
            }
        }
    }

   

    cout<<dp[n][target]<<"\n";
    queue<Pair> que;
    Pair obj("",n,target);
    que.push(obj);
  

    while (que.size() > 0)
    {
        Pair curr = que.front();que.pop();

        if(curr.i==0 || curr.j==0)
        {
            cout<<curr.psf<<"\n";
        }
        else{
            if(curr.j-arr[curr.i-1]>=0)
            {
                bool inc=dp[curr.i -1][curr.j-arr[curr.i-1]];
                if(inc == true)
                {
                    Pair newobj(to_string(curr.i-1) + " " + curr.psf , curr.i-1 , curr.j-arr[curr.i-1] ) ;
                    que.push(newobj);
                }
            }
            bool exc=dp[curr.i-1][curr.j];
            if(exc==true)
            {
                Pair newobj(curr.psf,curr.i-1,curr.j);     // Will not add index to our path as this elemnt is excluded
                que.push(newobj);
            }
        }
    }
    return 0;
}

