Pascal's Triangle II

Solution
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 40
class Solution {
public:
    //eg RowIndex=4
    // Ans will be 4c0 4c1 4c2 4c3 4c4
    // But finding factorial will make it o(n^2)
    // so we will use value from previous result
    // 1  4/1  4*3/1*2     4*3*2/1*2*3      4*3*2*1/1*2*3*4
    //         prev*(3/2)  prev*(2/3)       prev*(1/4)
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long int res=1;
        for(int i=0;i<=rowIndex;i++)
        {
            ans.push_back(res);
            res*=(rowIndex-i);
            res/=(i+1);
        }
        return ans;
    }
};
