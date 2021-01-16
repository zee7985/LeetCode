518. Coin Change 2
Medium

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1

class Solution {
public:
    // int coinHelper(int amount,int idx,vector<int> &coins)
    // {
    //     int count=0;
//         if(idx==coins.size() || amount==0){
//             {
//                 if(amount==0){
//                    return 1; 
//                 }
//             }
            
//         }
        
//         for(int i=idx;i<coins.size();i++)
//         {
//             if(amount-coins[i]>=0)
//             {
//                 count+=coinHelper(amount-coins[i],i,coins);
//             }
//         }
//         return count;
//     }
//     int change(int amount, vector<int>& coins) {
//         return coinHelper(amount,0,coins);
//     }
    
    //DP -Bottom up
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }

};
