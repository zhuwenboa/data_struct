#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        /*
        分析 本题类似于完全背包问题：因为给定的元素可以重复。并且不需要考虑顺序问题。
        所以需要将coin放在外循环，将目标amount放在内循环。 并且内循环正序
        */
        //将目标和放在内循环
        for(int i = 0; i < coins.size(); ++i)
        {
            int v = coins[i];
            for(int j = v; j <= amount; ++j)
            {
                dp[j] += dp[j-v];
            }
        }
        return dp[amount];
    }
};
