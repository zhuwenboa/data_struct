#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

有一个容量为 N 的背包，要用这个背包装下物品的价值最大，这些物品有两个属性：体积 w 和价值 v。

定义一个二维数组 dp 存储最大价值，其中 dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值。设第 i 件物品体积为 w，价值为 v，根据第 i 件物品是否添加到背包中，可以分两种情况讨论：

第 i 件物品没添加到背包，总体积不超过 j 的前 i 件物品的最大价值就是总体积不超过 j 的前 i-1 件物品的最大价值，dp[i][j] = dp[i-1][j]。
第 i 件物品添加到背包中，dp[i][j] = dp[i-1][j-w] + v。
第 i 件物品可添加也可以不添加，取决于哪种情况下最大价值更大。因此，0-1 背包的状态转移方程为：
            所以状态转移方程为: dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
*/

/*
W为背包总体积
N为物品数量
weights存储N个物品的重量
values 数组存储N个物品的价值
*/
class Solution
{
public:
    int Knapsack(int W, int N, vector<int>& weights, vector<int>& value)
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1));
        for(int i = 0; i < N; ++i) 
        {
            int w = weights[i-1];
            int v = value[i-1];
            for(int j = W; j > 0; --j)
            {
                if(j >= w)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
                else 
                    dp[i][j] = dp[i-1][j];
            }               
        }
        return dp[N][N];
    }
};

/*
空间优化

在程序实现时可以对 0-1 背包做优化。观察状态转移方程可以知道，前 i 件物品的状态仅与前 i-1 件物品的状态有关，
因此可以将 dp 定义为一维数组，其中 dp[j] 既可以表示 dp[i-1][j] 也可以表示 dp[i][j]。
     
    dp[j] = max(dp[j], dp[j-w] + v);
*/

    int Knapsack(int W, int N, vector<int>& weights, vector<int>& value)
    {
        vector<int> dp(W+1);
        for(int i = 0; i < N; ++i) 
        {
            int w = weights[i-1];
            int v = value[i-1];
            for(int j = W; j >= w; --j)
            {
                dp[j] = max(dp[j], dp[j-w] + v);
            }               
        }
        return dp[W];
    }