54. Spiral Matrix
Medium

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        if(A.size()==0)
        {
            return {};
        }
        
        int T,B,L,R,dir;  // 4 pointer top ,bottom ,left ,right
        T=0;
        B=A.size()-1;
        L=0;
        R=A[0].size()-1;
        dir=0;
        int i;
        vector<int> ans;
    
        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(i=L;i<=R;i++)
                    ans.push_back(A[T][i]);
                T++;
            }
            else if(dir==1)
            {
                for(i=T;i<=B;i++)
                    ans.push_back(A[i][R]);
                R--;
            }
            else if(dir==2)
            {
                for(i=R;i>=L;i--)
                    ans.push_back(A[B][i]);
                B--;
            }
            else if(dir==3)
            {
                for(i=B;i>=T;i--)
                    ans.push_back(A[i][L]);
                L++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
        


