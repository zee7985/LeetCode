Print All Paths With Maximum Gold

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.
8. Also, you have to print all paths with maximum gold.

Sample Input
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

Sample Output
33
4 d3 d1 d2 d3 d1 


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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>(m,0));
    for (int j = m; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (j == m - 1) {                            // Last Column
                dp[i][j] = arr[i][j];
            } else if (i == 0) {                        // First row ,two possible way to go front and diagonal down
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            } else if (i == n - 1) {                    // Last row ,two possible way to go front and diagonal up
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            } else {                                   // Middle -All three ways 
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }

    int max_= INT_MIN;                         // Find maximum of first row 
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i][0] > max_) {
            max_ = dp[i][0];
        }
    }

    cout<<max_<<"\n";

    queue<Pair> que;

    for (int i = 0; i < dp.size(); i++) {
        if (dp[i][0] == max_) {                    //Put all max value in que with row number
            Pair obj(to_string(i) + " ", i, 0); 
            que.push(obj);
        }
    }

    // Now traverse the matrix and choose the max value for finding path
    while (que.size() > 0) {
        Pair curr = que.front();que.pop();

        if (curr.j == m - 1) {         // As we reach last column ,print the ans
            cout<<curr.psf<<"\n";
            
        } else if (curr.i == 0) {
            int g = max(dp[curr.i][curr.j + 1], dp[curr.i + 1][curr.j + 1]);


            if (g == dp[curr.i][curr.j + 1]) {
                Pair newobj(curr.psf+ "d2 ", curr.i, curr.j + 1);
                que.push(newobj);        
            }

            if (g == dp[curr.i + 1][curr.j + 1]) {
                Pair newobj(curr.psf + "d3 ", curr.i + 1, curr.j+ 1);
                que.push(newobj);
            }
        } 
        else if (curr.i == n - 1) {
            int g = max(dp[curr.i][curr.j + 1], dp[curr.i - 1][curr.j + 1]);


            if (g == dp[curr.i - 1][curr.j + 1]) {
                Pair newobj(curr.psf+ "d1 ", curr.i - 1, curr.j +1);
                que.push(newobj);            
                }

            if (g == dp[curr.i][curr.j + 1]) {
                Pair newobj(curr.psf + "d2 ", curr.i, curr.j + 1);
                que.push(newobj);         
            }
        } 
        else {
            int g = max(dp[curr.i][curr.j + 1], max(dp[curr.i - 1][curr.j + 1], dp[curr.i + 1][curr.j + 1]));

            if (g == dp[curr.i - 1][curr.j + 1]) {
                Pair newobj(curr.psf + "d1 ", curr.i - 1, curr.j+ 1);
                que.push(newobj);
            }

            if (g == dp[curr.i][curr.j + 1]) {
                Pair newobj(curr.psf+ "d2 ", curr.i, curr.j + 1);
                que.push(newobj);        
            }

            if (g == dp[curr.i + 1][curr.j + 1]) {
                Pair newobj(curr.psf+ "d3 ", curr.i + 1, curr.j + 1);
                que.push(newobj);
            }
        }
    }
    return 0;
}

