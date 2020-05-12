#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//方法一：找到任一等于target的位置，然后线性的向左向右找到其最左最右的位置，最坏时间复杂度为O(N)。
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size() -1;
        int mid;
        bool flag = false;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                flag = true;
                break;
            }
            else if(nums[mid] > target)
            {
                high = mid -1;
            }
            else 
                low = mid + 1;
        }    
        if(flag == false)
            return {-1, -1};
        low = mid;
        high = mid;
        while(low > 0 && nums[low - 1] == target)
        {
            --low;
        }
        while(high < nums.size()-1 && nums[high + 1] == target)
        {
            ++high;
        }
        return vector<int>{low, high};
    }
};

//方法二： 通过两次二分查找找到最左和最右的位置
class Solution2 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.empty())
            return {-1, -1};
        int low = 0;
        int high = nums.size()-1;
        //第一次二分查找找到target最左的位置
        while(low < high)
        {
            int mid = (low + high) / 2; 
            if(nums[mid] >= target)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        if(nums[low] != target)
            return {-1, -1};
        int left = low;
        //第二次二分查找找到target最右的位置
        low = 0;
        high = nums.size() -1;
        while(low < high)
        {
            int mid = (low + high+1) / 2;
            if(nums[mid] <= target)
            {
                low = mid;
            }
            else 
            {
                high = mid-1;
            }
        }
        int right = high;
        return {left, right};
    }
};

int main()
{
    vector<int> vec{5,7,7,8,8,10};
    Solution2 res;
    vector<int> v = res.searchRange(vec, 8);
    for(auto a : v)
        std::cout << a << "\n";
}