#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    //回溯法
    void backtrack(vector<vector<int>>& ans, vector<int>& cur, int n, int k, int start)
    {
        if(k == 0)
        {
            ans.emplace_back(cur);
            return;
        }
        //起始条件为i=start是为了避免产生重复的答案
        for(int i = start; i <= n-k+1; ++i)
        {
            cur.emplace_back(i);
            backtrack(ans, cur, n, k-1, i+1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, n, k, 1);
        return ans;
    }
};