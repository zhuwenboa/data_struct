#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; ++i)
        {
            for(auto num : nums)
            {
                if(i >= num)
                {
                    if(dp[i] < INT32_MAX - dp[i-num])
                        dp[i] += dp[i - num];
                    else 
                        dp[i] = INT32_MAX;
                }
            }
        }
        return dp[target];
    }
};

int main()
{
    Solution res;
    vector<int> vec{3, 33, 333};
    std::cout << res.combinationSum4(vec, 10000) << "\n";
}