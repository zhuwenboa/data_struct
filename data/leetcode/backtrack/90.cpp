#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(nums, cur, 0);
        return ans;
    }
    void backtrack(const vector<int>& nums, vector<int>& cur, int start)
    {
        //空集也属于子集
        ans.emplace_back(cur);
        for(int i = start; i < nums.size(); ++i)
        {
            if(i > start && nums[i] == nums[i-1])
                continue;
            cur.emplace_back(nums[i]);
            backtrack(nums, cur, i+1);
            cur.pop_back();
        }
    }
};