#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    //暴力法 时间复杂度O(n^2) leetcode测试超出时间限制
    int reversePairs_1(vector<int>& nums) 
    {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i] > nums[j])
                {
                    ++count;
                }
            }
        }
        return count;
    }

    //归并排序法
    int mergesort(vector<int>& nums, vector<int>& tmp, int low, int high)
    {
        if(low >= high)
            return 0;
        int mid = (low+high) /2;
        int inv_count = mergesort(nums, tmp, low, mid) + mergesort(nums, tmp, mid+1, high);
        int i = low;
        int j = mid + 1;
        int k = low;
        while(i <= mid && j <= high)
        {
            if(nums[i] <= nums[j])
            {
                tmp[k] = nums[i];
                ++i;
                //计算出当前nums[i]的逆序数
                inv_count += (j - (mid + 1));
            }
            else
            {
                tmp[k] = nums[j];
                ++j;
            }
            ++k;            
        }
        for(int p = i; p <= mid; ++p)
        {
            tmp[k++] = nums[p];
            inv_count += (j - (mid + 1));
        }
        for(int p = j; p <= high; ++p)
        {
            tmp[k++] = nums[p];
        }
        copy(tmp.begin() + low, tmp.begin() + high + 1, nums.begin() + low);
        return inv_count;
    }

    //时间复杂度O(NlogN)
    int reversePairs_2(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> tmp(n);
        return mergesort(nums, tmp, 0, n-1);        
    }
};