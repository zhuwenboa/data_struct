#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
本题采用动态规划法，如果只判断一位数字那它肯定可以转换为字符 所以 dp[i] += dp[i-1];
两位数字必须要在 0-25之间才可以转换为字符 满足这个条件 则dp[i] += (dp[i-1] + dp[i-2]);
*/

class Solution 
{
public:
    int translateNum(int num) 
    {
        string nums = to_string(num);
        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < dp.size(); ++i)
        {
            dp[i] += dp[i-1];
            if(nums[i-2] == '1' || (nums[i-2] == '2' && nums[i-1] <= '5'))
                dp[i] += dp[i-2];
        }
        return dp[dp.size()-1];
    }
};