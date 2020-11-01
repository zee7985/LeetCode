Chef and Subtree MEXs Problem Code: SUBMEX

The MEX of a set of integers is defined as the smallest non-negative integer that does not belong to this set. For example, MEX({0,2,3})=1 and MEX({1,3})=0.

Chef has a tree with N nodes (numbered 1 through N). The tree is rooted at node 1. Chef wants to assign a non-negative integer to each node in such a way that each integer between 0 and N−1 (inclusive) is assigned to exactly one node.

For each node u, consider the integers assigned to the nodes in the subtree of u (including u); let au denote the MEX of these integers. Chef wants a1+a2+…+aN to be as large as possible. Find the maximum possible value of this sum.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N−1 space-separated integers p1,p2,…,pN−1. For each valid i, the node pi is the parent of the node i+1.
Output
For each test case, print a single line containing one integer ― the maximum sum of subtree MEX-s which can be obtained if you assign the weights optimally.

Constraints
1≤T≤5
2≤N≤105
1≤pi<i for each valid i
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
3
1 1
5
1 1 2 2
Example Output
4
9 


Main Aim : is to assign 0 to any of the leaf node so that maximum sum can be obtained .Find out the maximum of the  possibility 

#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> tree[1000005];

pair<int,int>  dfs(int u)
{
    int mex=0;
    int siz=1;

    for(int i:tree[u])
    {
        auto temp=dfs(i);
        mex=max(mex,temp.first);
        siz+=temp.second;
    }
    return { mex+siz,siz};
}

int32_t main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            tree[i].clear();

        }
        for(int i=2;i<=n;i++)
        {
            int a;
            cin>>a;
            tree[a].push_back(i);
        }
        cout<<dfs(1).first<<"\n";

    }

}
