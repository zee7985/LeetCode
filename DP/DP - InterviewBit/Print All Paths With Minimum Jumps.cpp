Print All Paths With Minimum Jumps
1. You are given a number N representing number of elements.
2. You are given N space separated numbers (ELE : elements).
3. Your task is to find & print  
    3.1) "MINIMUM JUMPS" need from 0th step to (n-1)th step.
    3.2) all configurations of "MINIMUM JUMPS".
    
Input   
10
3 3 0 2 1 2 4 2 0 0 

Output:
4
0 -> 3 -> 5 -> 6 -> 9 .
0 -> 3 -> 5 -> 7 -> 9 .


#include <bits/stdc++.h>
using namespace std;

class MinPair
{
    public:
    int idx;
    int stepsAllowed;
    int jumpsMade;
    string psf;

    MinPair( int idx, int stepsAllowed,int jumpsMade, string psf) {
        this->idx = idx;
        this->stepsAllowed = stepsAllowed;
        this->jumpsMade = jumpsMade;
        this->psf = psf;
    }
};

//   Solution :1. FInd Minjump dp
//             2. Put the element with maxjumps i.e element at index 0 into the queue
//             3.Now check for element with jumps of subsequence =maxjump-1(also it is should be lies between i+ stepsAllowed ) and put in the queue 
//             4. Print the pathsoFar when jumps==0 (because this is the destination)

void minstepsAllPath(vector<int> arr){
    vector<int> dp(arr.size()+1,0);

    for(int i=arr.size()-2;i>=0;i--){
        int minAns=INT_MAX/2;
        for(int j=i+1;j<arr.size() && j <=i + arr[i];j++){
            minAns=min(minAns,dp[j]);
        }
        dp[i]=minAns+1;
    }
    cout<<dp[0]<<"\n";
    queue<MinPair> que;

    //steps2:
 
    MinPair obj(0,arr[0],dp[0],to_string(0));
    que.push(obj);
     

    while(que.size()>0)
    {
        MinPair curr=que.front();que.pop();

        //steps4:
        if(curr.jumpsMade==0)
        {
            cout<<curr.psf<<" .\n";
        }

        //steps3:
        for(int j=curr.idx+1;j<arr.size() && j<=curr.idx + curr.stepsAllowed;j++)
        {
            if(dp[j]==curr.jumpsMade-1)
            {
                MinPair newobj(j,arr[j],dp[j],curr.psf + " -> " + to_string(j));
                que.push(newobj);
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    minstepsAllPath(arr);
}
