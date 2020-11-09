"""Kadane’s Algorithm
local = max ( arr[i] {initiate new array} , local + arr[i] {continue array});
global = max ( local , global );

Best Time to Buy and Sell Stock
"""

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int cost = prices[0];
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
            profit = max(profit,prices[i]-cost);
            cost = min(cost,prices[i]);}
        
        return profit;
    }
};
