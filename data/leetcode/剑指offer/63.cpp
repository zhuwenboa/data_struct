#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
* 动态规划 
* 状态转移方程为： 
*/
//我思考出的办法
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> dp(prices.size());
        if(prices.size() < 2)
            return 0;
        dp[0] = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            //如果dp[i-1]为0，证明当前还没有利润
            if(dp[i-1] == 0)
            {
                //如果当前的数小于前一个数，则继续没有利润
                if(prices[i] < prices[i-1])
                    dp[i] = 0;
                //算出当前的利润
                else 
                    dp[i] = prices[i] - prices[i-1];
            }
            else 
            {
                //计算出当前的利润
                dp[i] = dp[i-1] + prices[i] - prices[i-1];
                //如果利润小于0，则证明当前的数小于之前选择的数，将当前利润置为0，重新计算利润
                if(dp[i] < 0)
                    dp[i] = 0;
            }
        }
        int ans = 0;
        //遍历一遍dp找到最大的利润
        for(int i = 0; i < dp.size(); ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};

//方法二 也是动态规划 但只需要一次循环
//dp[i]为当前最大的利润 用min_price记录当前最少花费可以买入的股票
class Solution2
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int min_price = prices[0];
        int n = prices.size();
        vector<int> dp(n);
        for(int i = 1; i < n; i++)
        {
            min_price = min(min_price, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
        return dp[n - 1];
    }
};
