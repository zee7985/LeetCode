526. Beautiful Arrangement
Medium

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

 

Example 1:

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
Example 2:

Input: n = 1
Output: 1
 
Constraints:
1 <= n <= 15

class Solution {
public:
    //Time O(k) -k:Number of valid permutations
    // Check all the permutations if it is beautiful arrangement and increment count
    int count;
    void DFS(vector<int> arr, int pos){
        if(pos == arr.size()){
            count++;
            
        }
        for(int i = pos; i < arr.size(); i++){
            swap(arr[pos], arr[i]);
            if (arr[pos] % (pos + 1) == 0 || (pos + 1) % arr[pos] == 0)  //Instead of checking the whole array in base case check here and then only call the function(optimization)
                DFS(arr, pos + 1);
            swap(arr[pos], arr[i]);  //backtrack
        }
    }
     int countArrangement(int n) {
        count = 0;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        DFS(arr,0);
        return count;
    }  
};

