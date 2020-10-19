123. Best Time to Buy and Sell Stock III
Hard

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105


class Solution {
public:
    int dp[100000][2][3];
    int helper(vector<int> prices,int idx,int trans,bool buy)
    {
        if(idx==prices.size() || trans==2)
        {
            return 0;
        }
        if(dp[idx][buy][trans]!=-1)
        {
            return dp[idx][buy][trans];   
        }
        
        //3 option -Skip,Buy,Sell
    
        int ans=helper(prices,idx+1,trans,buy);         // skip
        if(buy)            // if Buy is 1, we have a choice to purchase the stock
        {
            ans=max(ans,helper(prices,idx+1,trans,false) -prices[idx]); // buy a stock
        }
        else
        {
            ans=max(ans,helper(prices,idx+1,trans+1,true) +prices[idx]);
        }
        return dp[idx][buy][trans]=ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,0,true);
        
    }
    
    //2. o(n) with o(n) space
    //second method is by using divide and conquer technique which is intuitive if we divide     //the entire stock days into 2 parts and we take the maximum profit from each part and       //just add them to get max profit.
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        
        vector<int> left(n),right(n);
        
        //Fill 1st transaction (LEFT)
        int leftMin = prices[0];
        for(int i=1;i<n;++i)
        {
            left[i] = max(left[i-1],prices[i]-leftMin);
            leftMin = min(leftMin,prices[i]);
        }
        
        //Fill 2nd transaction (RIGHT)
        int rightMax = prices[n-1];
        for(int i=n-2;i>=0;--i)
        {
            right[i] = max(right[i+1],rightMax-prices[i]);
            rightMax = max(rightMax,prices[i]);
        }
        
        //Find the max-profit value
        int profit = right[0];
        for(int i=1;i<n;++i)
            profit = max(profit,left[i-1]+right[i]);
        
        return profit;
    }
    
    //3. o(n) with o(1) space
    // explanation and code solving using state diagram.

    // For completing two transaction of buy and sell there is 4 states involve say s1, s2, s3, s4.
    // s1 is buying first share
    // s2 is selling first share
    // s3 is buying second share
    // s4 is selling second share

    // for s1 we can buy a share of spend money -prices[i] or continue skip.
    // for s2 we can sell a share earn profit of s1 + prices[i] or continue skip
    // for s3 we can buy a share spend money of s2 - prices[i] or continue skip
    // for s4 we can sell a share earn profit of s3 + prices[i] or continue skip

    public int maxProfit(vector<int> prices) {
        if (prices.size() == 0) return 0;
        
        int s1 = -prices[0], s2 = INT_MAX, s3 = INT_MIN, s4 = INT_MIN;
        for (int i = 1; i < prices.length; i++) {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }
        
        return max(0, s4);
    }
};


