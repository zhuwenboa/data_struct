#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0)
            return 0;
        vector<int> dp(s.size(), 0);
        int ans = 1;
        unordered_map<char, int> judge;
        judge[s[0]] = 0;
        int pre = -1;
        for(int i = 1; i < s.size(); ++i)
        {
            if(judge.count(s[i]) > 0)
            {
                if(pre < judge[s[i]])
                    pre = judge[s[i]];
            }
            judge[s[i]] = i;
            ans = max(ans, i - pre);
        }
        return ans;
    }
};
