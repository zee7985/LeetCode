Print All Longest Increasing Subsequences
1. You are given a number N representing number of elements.
2. You are given N space separated numbers (ELE : elements).
3. Your task is to find & print  
    3.1) Length of "Longest Increasing Subsequence"(LIS).
    3.2) All "Longest Increasing Subsequence(s)"(LIS).
    
Input: 10
10 22 9 33 21 50 41 60 80 1

output: 
6
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80


//   Solution :1. FInd Lis 
//             2. Put all the element with maxLength into the queue
//             3.Now check for element with length of subsequence =maxLength-1(also it is should be smaller than currEle) and put in the queue 
//             4. Print the pathsoFar when length==1 (because this is the minimum ans possible)


#include <bits/stdc++.h>
using namespace std;

class LISPair
{
    public:
    int len;
    int idx;
    int val;
    string psf;

    LISPair(int len, int idx, int val, string psf) {
        this->len = len;
        this->idx = idx;
        this->val = val;
        this->psf = psf;
        }
};



void LISstring(vector<int> arr)
{
    //Step1:
    vector<int> dp(arr.size(), 0);
    int max_ = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int maxI=0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j] )
            {
                maxI= max(maxI,dp[j] );
                
            }
        }
        dp[i]=maxI +1;
        if(max_<dp[i])
        {
            max_=dp[i];
        }
    }
    

    //cout<<max_<<" "<<maxIdx<<" "<<arr[maxIdx]<<" "<<to_string(arr[maxIdx]);
    cout<<max_<<"\n";
    queue<LISPair> que;

    //Step2:
    for(int i=0;i<dp.size();i++)
    {
        if(dp[i]==max_)
        {
            LISPair obj(max_,i,arr[i],to_string(arr[i]));
            que.push(obj);
        }
    }

    while(que.size()>0)
    {
        LISPair curr=que.front();que.pop();

        //Step4:
        if(curr.len==1)
        {
            cout<<curr.psf<<"\n";
        }

        //Step3:
        for(int j=curr.idx-1;j>=0;j--)
        {
            if(arr[j]<=curr.val && dp[j]==curr.len-1)
            {
                LISPair newobj(dp[j],j,arr[j],to_string(arr[j]) + " -> " + curr.psf);
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

    LISstring(arr);
}
