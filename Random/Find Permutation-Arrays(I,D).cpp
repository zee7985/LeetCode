Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]

Two Solution:With different ordering

//1.
//n :  5

// s = DIDD

// Return: [5, 1, 4, 3, 2]


vector<int> Solution::findPerm(const string A, int B) {
    int l=1,r=B;
    vector<int> ans;
  
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='I' )
        {
            ans.push_back(l);
            l++;
        }
        else
        {
            ans.push_back(r);
            r--;
        }
    }
    ans.push_back(l);
    return ans;
    
}

//2.Stack
//n :  5

// s = DIDD

// Return: [2,1,5,4,3]

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    int n = A.size();
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i+1);
    
        if(A[i]=='I'){
            while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
            }
        }
    }
    s.push(n+1);
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


