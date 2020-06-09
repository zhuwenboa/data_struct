#include<iostream>
#include<vector>

using namespace std;

//青蛙跳台阶问题
class Solution 
{
public:
    int numWays(int n) 
    {
        if(n == 0) 
            return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < dp.size(); ++i)
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        return dp[n];
    }
};