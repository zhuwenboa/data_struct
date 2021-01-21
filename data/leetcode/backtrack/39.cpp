#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx)
    {
        if(idx == candidates.size())
            return;
        if(target == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        //直接跳过
        dfs(candidates, target, ans, combine, idx+1);
        //选择当前数
        if(target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};

//回溯算法
class Solution2 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        if(candidates.empty())
            return {};
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(candidates, ans, cur, 0, 0, target);
        return ans;
    }
    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& cur, int sum, int start, const int& target)
    {
        if(sum == target)
        {
            ans.emplace_back(cur);
            return;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if(sum + candidates[i] > target)
                continue;
            cur.emplace_back(candidates[i]);
            backtrack(candidates, ans, cur, sum + candidates[i], i, target);
            cur.pop_back();
        }
    }
};