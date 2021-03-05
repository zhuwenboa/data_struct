#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(nums.empty())
            return 0;
        return quick_select(nums, 0, nums.size()-1, k-1);
    }
    int quick_select(vector<int> nums, int low, int high, int k)
    {
        if(low >= high)
            return nums[low];
        int m = q_sort(nums, low, high);
        if(m == k)
            return nums[m];
        if(m < k)
            return quick_select(nums, m+1, high, k);
        else 
            return quick_select(nums, low, m-1, k);
    }
    int q_sort(vector<int>& nums, int start, int end)
    {
        int judge = nums[start];
        while(start < end)
        {
            while(start < end && nums[end] <= judge)
                --end;
            swap(nums[end], nums[start]);
            while(start < end && nums[start] >= judge)
                ++start;
            swap(nums[start], nums[end]);
        }
        return start;
    }
};