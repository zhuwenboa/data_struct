#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty())
            return 0;
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(3));
    
        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益

        dp[0][0] = -prices[0];
        for(int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            //当前处于冷冻期 只能是将上一个持有的股票卖出
            dp[i][1] = dp[i-1][0] + prices[i];
            //手上不持有股票
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[size-1][1], dp[size-1][2]);
    }
};