#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    最长连续递增序列也是典型的动态规划
    将当前连续递增的长度用vector<int> dp;来保存
    因为当前长度只能由前一个长度推导而来
    状态转移方程为 dp[i] = dp[i-1] + 1;
    如果后面不大于当前的值那就设 dp[i] = 1;
    我们发现dp[i]只与dp[i-1]有关系，那么我们就可以用一个变量来代替它
    就是我们下面的代码了
*/

class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        //结果
        int ans = 1;
        //变量保存当前递增的长度
        int pre_sum = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                pre_sum++;
                ans = max(ans, pre_sum);
            }
            else 
            {
                pre_sum = 1;
            }
        }
        return ans;
    }
};