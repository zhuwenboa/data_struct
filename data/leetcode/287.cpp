#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;

//排序法 但是更改了原数组
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i -1] == nums[i])
                return nums[i];
        }   
        return -1;
    }
};

//二分查找法
class Solution2
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() -1;
        int mid;
        int ans = 0;
        while(low <= high)
        {
            mid = (low + high) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                cnt += (nums[i] <= mid);
            }
            //证明重复的数字在mid右边
            if(cnt <= mid)
            {
                low = mid + 1;
            }
            else
            { 
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};