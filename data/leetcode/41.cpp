#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//方法一 仿哈希表
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= 0)
                nums[i] = n+1;
        }
        for(int i = 0; i < n; ++i)
        {
            int num = abs(nums[i]);
            if(num <= n)
            {
                nums[num -1] = -abs(nums[num-1]);
            }
        }
        for(int i  = 0; i < n; ++i)
        {
            if(nums[i] >= 0)
                return i + 1;
        }
        return n + 1;
    }
};

//方法二 置换法
class Solution2
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] -1])
                swap(nums[i], nums[nums[i] -1]);
        }       
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
                return i + 1;
        }
        return n+1;
    }
};