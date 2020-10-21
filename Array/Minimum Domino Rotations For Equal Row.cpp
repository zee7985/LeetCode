 Minimum Domino Rotations For Equal Row


In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6


class Solution {
public:
    int majorityElement(vector<int> nums) {
        int count = 0;
        int candidate=0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
    

    // Find majority element in the array and find the no of element not equal to maj Ele and is present at             the same index in another array(Do this for both array and find min count)
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int majorityA=majorityElement(A);
        int majorityB=majorityElement(B);
        
        int countA=0;
        int countB=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==majorityA)
            {
                continue;
            }
            else if(A[i]!=majorityA)
            {
                if(B[i]==majorityA)
                {
                    countA++;
                }
                else
                {
                    countA=-1;
                    break;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(B[i]==majorityB)
            {
                continue;
            }
            else if(B[i]!=majorityB)
            {
                if(A[i]==majorityB)
                {
                    countB++;
                }
                else
                {
                    countB=-1;
                    break;
                }
            }
        }
        
        if(countA==-1 && countB==-1)
        {
            return -1;
        }
        
        if(countA==-1 && countB!=-1)
        {
            return countB;
        }
        if(countA!=-1 && countB==-1)
        {
            return countA;
        }
        
        return min(countA,countB);
    }
};
