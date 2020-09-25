74. Search a 2D Matrix
Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
//1/brute 0(n^2)

//2.o(m+n)-for solution see down
//=========================================
//3. optimal solution-o(log(mn))

//Here The first integer of each row is greater than the last integer of the previous row.
//so we can use binary search by considering 2d array as 1 sorted array.



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        
        int m=matrix[0].size();
        
        
        int s=0;
        int e=(m*n)-1;
        
        while(s<=e)
        {
            int mid=( s + (e-s)/2);
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(matrix[mid/m][mid%m]<target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return false;
    }
};



//2. Solution according to gfg where we have to  Search in a row wise and column wise sorted matrix
here first element is of each row is  not greater than last element of previous row.

mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
                      
this is better solution for leetcode but optimal sol for gfg

int search(int mat[4][4], int n, int x) 
{ 
    if (n == 0) 
        return -1; 
    int smallest = a[0][0], largest = a[n - 1][n - 1]; 
    if (x < smallest || x > largest) 
        return -1; 
    // set indexes for top right element 
    int i = 0, j = n - 1;  
    while (i < n && j >= 0) { 
        if (mat[i][j] == x) { 
            cout << "n Found at "
                 << i << ", " << j; 
            return 1; 
        } 
        if (mat[i][j] > x) 
            j--; 
        else // if mat[i][j] < x 
            i++; 
    } 
  
    cout << "n Element not found"; 
    return 0; // if ( i==n || j== -1 ) 
} 
Time complexity-O(m+n)
