s
Medium


On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].

// It will generate a complete binary tree in which the node is either 1 or 0. More specifically, the generation process will come from the following two way:

//     0                     1
//    / \        or         / \
//   0   1                 1   0
//   case 1                case 2
      
// Now, to know what is the K's value, we need to recurse back to row k/2, to see the K was originally created from 0 or 1, and then we return the 0 or 1 and do backtracking, and in each backtacking we can know current k's value based on backtracking return value and current k's even or odd.

// If we want to get the K-th number in line N,we must know which number generate it in line N-1 at first.
// Obviously,it is from the K/2  number in line N-1,it become an easier question that we can call itself.






class Solution {
public:
    
    int Kg( int n , int k)
    {
        if( n == 1) return 0;
        int prev_value= Kg( n - 1 , k/2);
        if( prev_value == 0)
        {
            return k%2 == 0 ? 0 : 1;
        }
        else
        {
            return k%2 == 0 ? 1 : 0;
        }
    }
    int kthGrammar(int n, int k) {
        return Kg( n , k - 1);     //0th indexed
    }
};