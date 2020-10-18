121. Best Time to Buy and Sell Stock
Easy

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

class Solution {
public:
    //1.Stack
//     int maxProfit(vector<int>& prices) {
//         if(prices.size()==0)
//         {
//             return 0;
//         }
        
//         int maxx=0;
//         stack<int>s;
//         s.push(prices[0]);
//         for(int i=1;i<prices.size();i++)
//         {
//             if(prices[i]<s.top())
//             {
//                 s.pop();
//                 s.push(prices[i]);
//             }
//             else
//             {
//                 maxx=max(maxx,prices[i]-s.top());
//             }
//         }
//         return maxx;
//     }
    
    
    //2.maintain two variables - minprice and maxprofit corresponding to the smallest valley 
    //and maximum profit (maximum difference between selling price and minprice) obtained so far respectively.
    int maxProfit(vector<int>& prices) {
        if( prices.size()== 0){
            return 0;
        }
        int profit = 0;
        int buy = prices[0];
        for(int i=1; i<prices.size(); i++){
            buy = min(buy,prices[i]);
            profit = max(profit,prices[i]-buy);
        }
        return profit;
    }
};
