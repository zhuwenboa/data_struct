#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int cuttingRope(int n) 
    {
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; ++i)
        {
            int max = 0;
            for(int j = 1; j <= i / 2; ++j)
            {
                int product = dp[j] * dp[i - j];
                if(product > max)
                    max = product;
                dp[i] = max;
            }
        }
        return dp[n];
    }
};