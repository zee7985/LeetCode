Flip
Asked in:  
VMWare
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].

//Solution:

// Note what is the net change in number of 1s in string S when we flip bits of string S.
// Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.

// So, number of 1s increase by A - B. We want to choose a subarray which maximises this.
// Note, if we change 1s to -1 and change 0 to 1, then sum of values will give us A - B.
// Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.
vector<int> Solution::flip(string s) {
    int count=0,ans=0,l=0,r=0;
    int strt=0,ones=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            ones++;
            count--;
        }
        if(s[i]=='0') count++;
        
        if(count>ans)
        {
            ans=count;
            l=strt;
            r=i;
            
        }
        
        if(count<0)
        {
            strt=i+1;
            count=0;
        }
        
        if(ones==s.length()) return vector<int>{};
    }
    return vector<int>{l+1,r+1};
}
