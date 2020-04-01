#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution 
{
public:
    enum Index  
    {
        GOOD,
        BAD,
        UNKNOW
    };
    bool canJump(vector<int>& nums) 
    {
        judge.resize(nums.size(), UNKNOW);
        judge[nums.size()-1] = GOOD;
        return dp_huisu(0, nums);
    }
    //暴力回溯算法
    bool huisu(int position, vector<int>& nums)
    {
        if(position == nums.size() -1)
            return true;
        //当前位置可以跳到最远的位置
        int Longjumplen = min(position + nums[position],  static_cast<int>(nums.size() -1) );
        //将所有可能都遍历一遍
        for(int i = position + 1; i <= Longjumplen; ++i)
        {
            if(huisu(i, nums))
                return true;
        }
        return false;
    }
    //动态规划，对回溯进行标记，自顶向下
    bool dp_huisu(int position, vector<int>& nums)
    {
        if(judge[position] != UNKNOW)
            return judge[position] == GOOD ? true : false;
        //当前位置可以跳到最远的位置
        int Longjumplen = min(position + nums[position],  static_cast<int>(nums.size() -1) );
        for(int i = position + 1; i <= Longjumplen; ++i)
        {
            if(dp_huisu(i, nums))
            {
                judge[position] = GOOD;
                return true;
            }
        }
        judge[position] = BAD;
        return false;
    }

    //自底向上的动态规划
    bool canJump1(vector<int>& nums)
    {
        vector<bool> f(nums.size(), false);
        f[nums.size() -1] = true;
        for(int i = nums.size()-1; i >=0; --i)
        {
            int furthestJump = min(i + nums[i], static_cast<int>(nums.size()-1));
            for(int j = i+1; j <= furthestJump; ++j)
            {
                if(f[j] == true)
                    f[i] = true;
            }
        }
        return f[0];
    }

    //贪心算法
    //从右向左迭代
    bool canJump2(vector<int>& nums)
    {
        int lastPos = nums.size() -1;
        for(int i = nums.size()-1; i>=0; --i)
        {
            if(i + nums[i] >= lastPos)
                lastPos = i;
        }
        return lastPos == 0;
    }
    vector<Index> judge;
};