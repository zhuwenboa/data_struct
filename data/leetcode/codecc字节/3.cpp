#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        int ans = 1;
        int pre = 0;
        unordered_map<char, int> hash_;
        hash_[s[0]] = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(hash_.count(s[i]))
            {
                if(pre <= hash_[s[i]])
                    pre = hash_[s[i]] + 1;
            }
            hash_[s[i]] = i;
            ans = max(ans, i - pre + 1);
        }
        return ans;
    }
};