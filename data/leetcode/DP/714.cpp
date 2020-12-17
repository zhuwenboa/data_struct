#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }
    /*
        由于dp[i][0] 和dp[i][1]只与dp[i-1][0] 和dp[i-1][1]有关
        所以可以只用两个遍量 buy 或者sail变量保存
    */
    /*
        sail = 0;
        buy = -prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            sail = max(sail, buy + prices[i] - fee);
            buy = max(buy, sail - prices[i]);
        }
    */
};