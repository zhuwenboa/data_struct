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
        int max_profit = 0;
        int min_price = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] > min_price)
                max_profit = max(max_profit, prices[i] - min_price);
            else 
                min_price = prices[i];
        }
        return max_profit;
    }
};