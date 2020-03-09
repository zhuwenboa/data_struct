#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //找到波谷和波峰 方法一
    int maxProfit(vector<int>& prices) 
    {
        int valley;
        int peak;
        int i = 0;
        int maxprofit = 0;
        while(i < prices.size() -1)
        {
            while(i < prices.size() -1 && prices[i] >= prices[i+1])
                ++i;
            valley = prices[i]; //找到波谷
            while(i < prices.size() -1 && prices[i] <= prices[i+1])
                ++i;
            peak = prices[i];  //找到波峰
            maxprofit += peak - valley;
        }
        return maxprofit;
    }

    //方法二 贪心算法
    int maxProfit2(vector<int> &prices)
    {
        int maxprofit = 0;
        for(int i = 0; i < prices.size() -1; ++i)
        {
            if(prices[i+1] > prices[i])
                maxprofit += prices[i+1] - prices[i];
        }
        return maxprofit;
    }
};