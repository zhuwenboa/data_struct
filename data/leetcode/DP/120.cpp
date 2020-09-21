#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 三角形最小路径和

/*
    动态规划： dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + value[i][j];
    因为dp[i][j]只与dp[i-1][..]有关，所以可以简化为一维数组
    dp[j] = min(dp[j], dp[j+1]) + value[i][j];
*/

class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> dp(triangle.size()+1);
        for(int i = triangle.size()-1; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                dp[j] = min(dp[j+1], dp[j]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};