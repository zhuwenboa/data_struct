#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<string> permutation(string s) 
    {
        if(s.empty())
            return {};
        sort(s.begin(), s.end());
        vector<string> ans;
        string cur;
        vector<bool> judge(s.size(), false);
        backtrack(ans, cur, 0, s, judge);
        return ans;
    }
    void backtrack(vector<string>& ans, string& cur, int index, const string& s, vector<bool>& judge)
    {
        if(cur.size() == s.size())
        {
            ans.emplace_back(cur);
            return;
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(judge[i] || (i > 0 && s[i] == s[i-1] && !judge[i-1]) )
                continue;
            judge[i] = true;
            cur.push_back(s[i]);
            backtrack(ans, cur, i + 1, s, judge);
            judge[i] = false;
            cur.pop_back();
        }
    }
};