#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> judge;
        for(auto a : wordDict)
            judge.insert(a);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dp[j] && judge.find(s.substr(j, i-j)) !=  judge.end())
                {
                    dp[i] = true;
                    break;
                }       
            }
        }
        return dp[s.size()];
    }
};