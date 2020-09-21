#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> vis;

    void backtrarck(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm)
    {
        if(idx == nums.size())
        {
            ans.emplace_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            //这个判断条件保证了对于重复数的集合，一定是从左往右逐个填入的
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1]))
                continue;
            vis[i] = 1;
            perm.emplace_back(nums[i]);
            backtrarck(nums, ans, idx+1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrarck(nums, ans, 0, perm);
        return ans;        
    }
};