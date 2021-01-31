#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    char firstUniqChar(string s) 
    {
        if(s.empty())
            return ' ';
        vector<pair<int, int>> judge(26, {0, 0});
        int min_index = INT32_MAX;
        for(int i = 0; i < s.size(); ++i)
        {
            pair<int, int> t = judge[s[i] - 'a'];
            judge[s[i] - 'a'] = {i, t.second +1};
        }
        for(int i = 0; i < judge.size(); ++i)
        {
            if(judge[i].second == 1)
                min_index = min(min_index, judge[i].first);
        }
        if(min_index == INT32_MAX)
            return ' ';
        return s[min_index];
    }
};