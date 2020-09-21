#include<iostream>
#include<algorithm>
#include<vector>
//打家劫舍问题
using namespace std;

/*
*    这是我最开始想到的思路
*    状态转移方程为 dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
*    因为我的思路是当前最大的金额就是相隔一天或者相隔两天的金额相加，
*    为什么是相隔一天和两天呢，因为如果相隔三天那它的金额肯定已经被判断过了 
*    看个例子(3 2 3 4 5) 5和1相隔三天，那1肯定已经被中间的金额加上了，所以就不用在去判断了\
*    这个思路虽然是动态规划，但是它是我举例验证出来的，不是通过正常的规律来推导出来的
*/
class Solution1
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for(int i = 3; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};

/*
    正常的思路应该是 当前dp[i]的结果有两种情况，类似于背包问题 比较加上当天的金额和相邻的金额哪个更大
    状态转移方程为: dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
*/

class Solution2
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], dp[1]);
        for(int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};