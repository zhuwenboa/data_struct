#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size() < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            if(nums[i] > 0)
                return ans;
            if(i >= 1 && nums[i] == nums[i-1])
                continue;
            int pre = i + 1;
            int last = nums.size() -1;
            while(pre < last)
            {
                int cur_sum = nums[i] + nums[pre] + nums[last];
                if( cur_sum == 0)
                {
                    ans.push_back({nums[i], nums[pre], nums[last]});
                    ++pre;
                    --last;
                    while(pre < last && nums[pre] == nums[pre - 1])
                        ++pre;
                    while(pre < last && nums[last] == nums[last + 1])
                        --last;
                }
                else if(cur_sum < 0)
                    pre++;
                else 
                    last--;
            }
        }
        return ans;
    }
};