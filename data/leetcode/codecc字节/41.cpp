#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] <= 0)
                nums[i] = size + 1;
        }
        for(int i = 0; i < size; ++i)
        {
            int cur_num = abs(nums[i]);
            if(cur_num <= size)
            {
                nums[cur_num - 1] = -abs(nums[cur_num - 1]);
            }
        }
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] > 0)
                return i + 1;
        }
        return size + 1;
    }
};