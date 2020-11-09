#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    //方法一 动态规划
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size() < 1)
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = i -1; j >=0; --j)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }
            }
            if(dp[i] == 0)
                dp[i] = 1;
        }
        int max_len = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(dp[i] > max_len)
                max_len = dp[i];
        }
        return max_len;
    }
};

//方法二 贪心+二分查找
class Solution2
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else
            {
                // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                int l = 1, r = len, pos = 0; 
                while (l <= r) 
                {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) 
                    {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
