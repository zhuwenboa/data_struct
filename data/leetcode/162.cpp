#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
/*
    int findPeakElement(vector<int>& nums) 
    {
        int mid = nums.size() / 2;
        return find(nums, 0, mid, nums.size() -1);   
    }
    int find(vector<int> &nums, int low, int mid, int high)
    {
        //判断条件成立
        if(low < high && mid > low && mid < high && nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if(low < high)
        {
            return find(nums, low, (mid + low) / 2, mid -1);
            return find(nums, mid + 1, (high + mid) / 2, high);
        }
    }
*/
    //递归二分查找
    int findPeakElement(vector<int>& nums)
    {
        return find(nums, 0, nums.size() -1);
    } 
    int find(vector<int> &nums, int low, int high)
    {
        if(low == high)
            return low;
        int mid = (low + high) / 2;
        if(nums[mid] > nums[mid + 1])
        {
            return find(nums, low, mid);
        }
        return find(nums, mid + 1, high);
    }
};

int main()
{
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    Solution res;
    std::cout << res.findPeakElement(nums) << "\n";
}

