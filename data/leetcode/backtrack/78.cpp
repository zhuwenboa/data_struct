#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) 
    {
        if (cur == nums.size()) 
        {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        dfs(0, nums);
        return ans;
    }
};

class Solution2 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if(nums.empty())
            return {};
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, nums, cur, 0);
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& cur, int start)
    {
        ans.emplace_back(cur);
        for(int i = start; i < nums.size(); ++i)
        {
            cur.emplace_back(nums[i]);
            backtrack(ans, nums, cur, i+1);
            cur.pop_back();
        }           
    }
};

