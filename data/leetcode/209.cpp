#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//方法一 基于前缀和加二分查找 时间复杂度为O(NlogN)
class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int ans = INT32_MAX;
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(sum[i] >= s)
                ans = min(ans, i+1);
            int target = s + sum[i];
            int index = binary_search(sum, i, nums.size()-1, target);
            if(index != -1)
                ans = min(ans, index - i);
        }
        return ans == INT32_MAX ? 0 : ans;
    }
    //二分查找 找到第一个大于等于target的位置
    int binary_search(vector<int>& sum, int low, int high, int target)
    {

        while(low < high)
        {
            int mid = (low + high) / 2;
            if(sum[mid] < target)
                low = mid + 1;
            else 
                high = mid;
        }   
        return sum[low] >= target ? low : -1;
    }
};


//方法二 双指针滑动窗口
class Solution2 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int cur = 0;
        int pre = 0;
        int sum = 0;
        int ans = INT32_MAX;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            cur++;
            if(sum >= s)
            {
                ans = min(ans, (cur-pre));
                while(pre < cur)
                {
                    if(sum - nums[pre] >= s)
                    {
                        sum -= nums[pre];
                        pre++;
                        ans = min(ans, (cur-pre)); 
                    }
                    else 
                        break;
                }
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

int main()
{
    vector<int> num{2, 3, 1, 2, 4, 3};
    Solution2 res;
    std::cout << res.minSubArrayLen(7, num) << "\n";
}