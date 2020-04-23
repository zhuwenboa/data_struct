#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> count;
    //迭代法 
    int dp(vector<int>& coins, int rem)
    {
        if(rem < 0)
            return -1;
        if(rem == 0)
            return 0;
        //如果该子集被计算过，就直接返回,避免重复计算
        if(count[rem -1] != 0) 
            return count[rem -1];
        int Min = INT32_MAX;
        for(int coin : coins)
        {
            int res = dp(coins, rem -coin);
            if(res >= 0 && res < Min)
            {
                Min = res + 1;
            }
        }
        count[rem -1] =  Min == INT32_MAX ? -1 : Min;
        return count[rem -1];

    }

    //自底向上
    int dp2(vector<int>& coins, int amount)
    {
        vector<int> DP(amount+1, amount+1);
        DP[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(auto coin : coins)
            {
                if(coin <= i)
                {
                    DP[i] = min(DP[i], DP[i - coin] + 1);
                }
            }
        }
        return DP[amount] > amount ? -1 : DP[amount];
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount < 1)
            return 0;
        count.resize(amount);  
        return dp(coins, amount);
    }
};

int main()
{
    Solution res;
    vector<int> vec{186, 419, 83, 408};
    std::cout << res.coinChange(vec, 6249) << "\n";
}