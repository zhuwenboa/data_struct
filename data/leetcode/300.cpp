#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
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