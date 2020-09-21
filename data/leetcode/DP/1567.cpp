#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int getMaxLen(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0)
            return 0;
        vector<int> p_dp(size); //存储乘积为正数的最大和
        vector<int> n_dp(size); //存储乘积为负数的最大和
        p_dp[0] = nums[0] > 0 ? 1 : 0;
        n_dp[0] = nums[0] < 0 ? 1 : 0;
        int result = p_dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
            {
                p_dp[i] = p_dp[i-1] + 1;
                n_dp[i] = n_dp[i-1] > 0 ? n_dp[i-1] + 1 : 0;
            }
            else if(nums[i] < 0)
            {
                p_dp[i] = n_dp[i-1] > 0 ? n_dp[i-1] + 1 : 0;
                n_dp[i] = p_dp[i-1] + 1;
            }
            else 
            {
                p_dp[i] = 0;
                n_dp[i] = 0;
            }
            result = max(result, p_dp[i]);
        }
        return result;
    }
};