#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> count;
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

    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount < 1)
            return 0;
        count.resize(amount);  
        return  dp(coins, amount);
    }
};

int main()
{
    Solution res;
    vector<int> vec{186, 419, 83, 408};
    std::cout << res.coinChange(vec, 6249) << "\n";
}