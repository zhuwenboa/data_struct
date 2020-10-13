#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    //回溯算法 超出时间限制
    void backtrack(vector<int>& nums, int idx, int left_sum, int right_sum, bool &flag)
    {
        if(flag == true)
            return;
        if(idx == nums.size() -1)
            return;
        if(left_sum == right_sum)
        {
            flag = true;
            return;
        }
        //选择将当前数字分到一组
        backtrack(nums, idx+1, left_sum + nums[idx+1], right_sum - nums[idx+1], flag);
        //不选择当前数字
        backtrack(nums, idx+1, left_sum, right_sum, flag);

    }

    bool canPartition(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return false;
        int sum = 0;
        bool flag = false;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        backtrack(nums, 0, 0, sum, flag);
        backtrack(nums, 0, nums[0], sum - nums[0], flag);
        return flag;
    }
};


//动态规划，将该问题转换为类似于背包问题
class Solution2 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 2)
            return false;
        int sum = 0;
        int max_sum = 0;
        for(auto a : nums)
        {
            max_sum = max(max_sum, a);
            sum += a;
        }
        //如果sum为奇数，则返回false
        if(sum & 1)
            return false;
        int target = sum / 2;
        if(max_sum > target)
            return false;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        for(int i = 0; i < n; ++i)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; ++i)
        {
            int num = nums[i];
            for(int j = 1; j <= target; ++j)
            {
                if(j >= num)
                {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j - num];
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][target];
    }
};

/*
    可以进行空间优化，dp[i][j] 只与dp[i-1][j] 或者dp[i-1][j-nums[i]]有关
    所以可以优化为dp[j] |= dp[j - nums[i]];
    初始化 vector<int> dp(target+1, 0);
    for(int i = 0; i < n; ++i)
    {
        int num = nums[i];
        for(int j = target, j >= num; --j)
        {
            dp[j] |= dp[j - num];
        }
    }
    return dp[target];
*/
