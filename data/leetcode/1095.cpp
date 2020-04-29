#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class MountainArray 
{
public:
    MountainArray(vector<int> vec) : nums(vec) {}
    int get(int index)
    {
        return nums[index];
    }
    int length()
    {
        return nums.size();
    }
private:  
    vector<int> nums;
};

class Solution 
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
         int m;
         int low = 0;
         int len = mountainArr.length()-1;
         int high = len;
         //找到峰值
         while(low < high)
         {
            m = (low + high) / 2;
            if(mountainArr.get(m) < mountainArr.get(m+1))
                low = m + 1;
            else
                high = m;
         } 
         int mid;
         low = 0;
         high = m;
         while(low <= high)
         {
            mid = (low + high) / 2;
            if(target == mountainArr.get(mid))
                return mid;
            if(target > mountainArr.get(mid))
                low = mid + 1;
            else
                high = mid -1;
         }
         low = m+1;
         high = len;
         //峰值右边的数组，是降序排列的，所以要将二分查找稍微改变一下
         while(low <= high)
         {
            mid = (low + high) / 2;
            if(target == mountainArr.get(mid))
                return mid;
            if(target > mountainArr.get(mid))
                high = mid -1;
            else
                low = mid + 1;
         }
         return -1;
    }
};

int main()
{
    vector<int> vec = {0, 5, 3, 1};
    MountainArray t(vec);
    Solution res;
    std::cout << res.findInMountainArray(1, t) << "\n";
}