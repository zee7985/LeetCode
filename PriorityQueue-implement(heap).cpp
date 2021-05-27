#include<bits/stdc++.h>
using namespace std;

#define testcases int t; cin>>t; while(t--)
#define int long long
const int MOD =  1e9 + 7;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

class Heap {

    vector<int> v;
    bool isMax = true;

    bool compare(int ch, int par)
    {
        // return true i.e we need to swap as it is wrong
        if (isMax)
        {
            return ch > par; // maxHeap and child greater than parent is wrong, so swap
        }

        return ch < par;
    }

public:

    Heap() {}

    Heap(bool x)
    {
        isMax = x;
    }

    // Build array into heap can be done inplace i.e on input array only if no insertions
    Heap(vector<int> arr, bool x = true)
    {
        isMax = x;
        v = arr;

        // Method 1 - O(NlogN)
        // for(int i = 0;i<arr.size();i++)
        // {
        //     upheapify(i);
        // }

        // Method 2 - O(N)
        // Last non leaf = parent of last leaf
        int lnf = ((arr.size() - 1) - 1) / 2;

        for (int i = lnf; i >= 0; i--)
        {
            downHeapify(i, arr.size());
        }

    }

    void push(int x)
    {
        v.push_back(x);
        int i = v.size() - 1;
        upheapify(i);
    }

    void pop()
    {
        if (v.empty()) return;

        v[0] = v.back();
        int last = v.size() - 1;
        v.erase(v.begin() + last);

        downHeapify(0, v.size());
    }

    int top()
    {
        if (!v.empty()) return v[0];
        return -1;
    }

    int size()
    {
        return v.size();
    }

    // Goes from child to parent
    void upheapify(int ci)
    {
        int pi = (ci - 1) / 2;

        if (pi >= 0 && compare(v[ci], v[pi]))
        {
            swap(v[pi], v[ci]);
            upheapify(pi);
        }
    }

    void downHeapify(int pi, int n)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        int idx = pi;

        if (lci < n && compare(v[lci], v[idx]))
        {
            idx = lci;
        }

        if (rci < n && compare(v[rci], v[idx]))
        {
            idx = rci;
        }

        if (pi != idx)
        {
            swap(v[pi], v[idx]);
            downHeapify(idx, n);
        }
    }
};

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    FASTIO;


    Heap h(true);
    for (int i = 1; i <= 5; i++) h.push(i);

    while (h.size() > 0)
    {
        cout << h.top() << " ";
        h.pop();
    }

    cout << endl;

    vector<int> v = {1, 4, 5, 3, 5, -1, -1, -2};
    Heap h2(v, false);

    while (h2.size() > 0)
    {
        cout << h2.top() << " ";
        h2.pop();
    }

}
