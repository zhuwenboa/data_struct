#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int minprice = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            maxprofit = max(maxprofit, prices[i] -minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprofit;
    }
};