#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(int cur, int last, vector<int>& nums)
    {
        if(cur == nums.size())
        {
            if(temp.size() >= 2)
                ans.push_back(temp);
            return;
        }
        if(nums[cur] > last)
        {
            temp.push_back(nums[cur]);
            dfs(cur+1, nums[cur], nums);
            temp.pop_back();
        }
        if(nums[cur] != last)
        {
            dfs(cur+1, last, nums);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        dfs(0, INT32_MIN, nums);
        return ans;
    }
};