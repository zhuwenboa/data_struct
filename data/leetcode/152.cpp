#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_sum = nums[0];
        int min_sum = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            int mx = max_sum, mn = min_sum;
            max_sum = max(mx * nums[i], max(nums[i], mn * nums[i]));
            min_sum = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(ans, max_sum);
        }
        return ans;
    }
};