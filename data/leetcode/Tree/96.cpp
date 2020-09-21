/*
*leetcode 96题 不同的二叉搜索树
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        //卡特兰数公式
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }    
        return dp[n];
    }
};