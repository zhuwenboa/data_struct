#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size() -1;
        int low = 0;
        int high = n;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[0] <= nums[mid])
            {
                if(target < nums[mid] && target >= nums[0])
                    high = mid -1;
                else 
                    low = mid + 1;
            }
            else 
            {
                if(target > nums[mid] && target <= nums[n])
                    low = mid + 1;
                else 
                    high = mid -1;
            }
        }
        return -1;
    }
};