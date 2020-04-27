#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//方法一 先找到旋转点，然后左右子数组均为有序数组，然后进行二分查找。但是在找旋转点的时候最坏情况时间复杂度为O(N)
class Solution1
{
public:
    void search_index(vector<int>& nums, int target, int low, int high, int& res)
    {
        if(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                res = mid;
                return;
            }
            if(mid-1 >= 0 && mid+1 < nums.size())
            {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                {
                    res = mid;
                    return;
                }
            }
            if(res >= 0)
                return;
            search_index(nums, target, low, mid-1, res);
            search_index(nums, target, mid +1, high, res);
        }
    }

    int search(vector<int>& nums, int target) 
    {
        int division = -1;
        search_index(nums, target, 0, nums.size()-1, division);
        if(division == -1)
            return division;
        if(target == nums[division])
            return division;
        else
        {
            int low, high;
            if(target >= nums[0] && target < nums[division])
            {
                low = 0;
                high = division-1;
            }
            else
            {
                low = division+1;
                high = nums.size()-1;
            }
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(nums[mid] == target)
                    return mid;
                if(nums[mid] > target)
                    high = mid -1;
                else
                    low = mid + 1;
            }
            return -1;
        }
    }
};

/*
*方法二 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
*此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
*/
class Solution2 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int len = nums.size();
        if(len == 0)    
            return -1;
        int low = 0, high = len-1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(target == nums[mid])
                return mid;
            //判断分开的数组哪个是有序的
            if(nums[0] <= nums[mid])  //0-mid 数组有序
            {
                if(target >= nums[0] && target < nums[mid])
                    high = mid -1;                    
                else
                    low = mid + 1;
            } 
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid -1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> vec{3,1};
    Solution2 res;
    std::cout << res.search(vec, 1) << "\n";
}