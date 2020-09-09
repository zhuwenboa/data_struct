#include<iostream>
#include<algorithm>
#include<vector>

using namespace  std;

class Solution 
{
public:
    void dfs(vector<int>& candidate, int target, vector<vector<int>>& ans, vector<int>& combine, int start)
    {
        if(target == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        for(int i = start; i < candidate.size() && target - candidate[i] >=0; ++i)
        {
            //回溯剪枝避免重复
            //https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
            if(i > start && candidate[i] == candidate[i-1])
                continue;
            combine.emplace_back(candidate[i]);
            dfs(candidate, target-candidate[i], ans, combine, i+1);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, combine, 0);
        return ans;        
    }
};
