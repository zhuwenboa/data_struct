#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int cur_ans = 0;
        int max_ans = INT32_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            cur_ans += nums[i];
            max_ans = max(max_ans, cur_ans);
            if(cur_ans < 0)
                cur_ans = 0;
        }
        return max_ans;
    }
};