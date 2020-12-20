#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i)
        {
            for(int tmp : nums)
            {
                if(i >= tmp)    
                    dp[i] += dp[i-tmp];
            }
        }
        return dp[target];
    }
};

//回溯算法 超出时间限制
class Solution2 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(nums.size() == 0)
            return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0, ans);
        return ans;
    }
    void dfs(vector<int>& nums,int target, int cur_sum, int& ans)
    {
        if(cur_sum == target)
        {
            ans++;
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(cur_sum + nums[i] > target)
                break;
            cur_sum += nums[i];
            dfs(nums,  target, cur_sum, ans);
            cur_sum -= nums[i];
        }
    }
};