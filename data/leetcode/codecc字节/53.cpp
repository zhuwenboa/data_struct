#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.empty())
            return INT32_MIN;
        int cur_sum = 0;
        int max_sum = INT32_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] + cur_sum < nums[i])
                cur_sum = nums[i];
            else 
                cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};