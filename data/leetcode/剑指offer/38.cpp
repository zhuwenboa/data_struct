#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

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
        vector<bool> judge(s.size(), false);
        string cur;
        backtrack(s, ans, cur, judge);
        return ans;
    }
    void backtrack(const string& s, vector<string>& ans, string& cur, vector<bool>& judge)
    {
        if(cur.size() == s.size())
        {
            ans.emplace_back(cur);
            return;
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(judge[i] || (i > 0 && s[i] == s[i-1] && !judge[i-1]))
                continue;
            judge[i] = true;
            cur.push_back(s[i]);
            backtrack(s, ans, cur, judge);
            judge[i] = false;
            cur.pop_back();
        }
    }
};