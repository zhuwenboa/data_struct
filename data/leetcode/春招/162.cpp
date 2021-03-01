#include<iostream>
#include<vector>
#include<algorithm>

using  namespace std;

//二分查找
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.empty())
            return -1;
        int low = 0;
        int high = nums.size()-1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid + 1])
                high = mid;
            else 
                low = mid + 1;
        }
        return low;
    }
};