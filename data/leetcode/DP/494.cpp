#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//类似于背包问题
/*
题目描述
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
*/
/*
* 题目描述：
* 有两种方法可以得到当前数的方法和 "+"和"-"
* i为当前数的下标，j为记录的值
* 所以状态转移方程 dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]];
* 类似背包问题：因为第i个数只与第i-1个数有关系 所以我们可以将二维数组简化为一维数组
* dp[j] = dp[j-nums[i]] + dp[j+nums[i]];
*/


/*
思路就是把整个集合看成两个子集，Q表示整个集合，P表示正数子集，N表示负数子集， T表示目标和，
用S(X)表示集合的求和函数，集合中均为非负数，N集合是指选中这部分元素作为负数子集。

S(P)−S(N)=T

S(P)+S(N)+S(P)−S(N)=T+S(P)+S(N)

2S(P) = S(Q) + T
2S(P)=S(Q)+T
也就是： 正数集和的两倍 == 等于目标和 + 序列总和 这就回归到背包问题
*/
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = 0;
        for(auto num : nums)
            sum += num;
        if(S > sum || (S + sum) % 2 == 1)
            return 0;
        int new_targe = (S + sum) / 2;
        vector<int> dp(new_targe+1);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            int v = nums[i];
            for(int j = new_targe; j >= v; --j)
            {
                    dp[j] += dp[j - v];
            }
        }
        return dp[new_targe];
    }
};
 

//暴力法  枚举所有可能
class Solution2
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int count = 0;
        violence(nums, 0, 0, S, count);
        return count;
    }
    void violence(vector<int>& nums, int index, int value, int target, int& count)
    {
        if(index == nums.size())
        {
            if(value == target)
            {
                ++count;
            }
        }
        else 
        {
            violence(nums, index+1, value+nums[index], target, count);
            violence(nums, index+1, value-nums[index], target, count);

        }
    }
};
