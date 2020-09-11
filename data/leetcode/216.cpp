#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    void dfs(vector<vector<int>>& ans, vector<int>& combine, int start, int k, int n)
    {
        if(k == 0 && n == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        if(n < 0)
            return;
        for(int i = start; i <= 9; ++i)
        {
            if(n - i < 0)
            {
                return;
            }
            combine.emplace_back(i);
            dfs(ans, combine, i+1, k-1, n-i);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> combine;
        vector<vector<int>> ans;
        dfs(ans, combine, 1, k, n);
        return ans;
    }
};

int main()
{
    Solution res;
    vector<vector<int>> r = res.combinationSum3(3, 7);
}