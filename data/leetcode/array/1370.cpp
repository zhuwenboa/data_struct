#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    string sortString(string s) 
    {
        if(s.empty())
            return "";
        vector<int> num(26);
        for(const char& a : s)
            num[a - 'a']++;
        string ans;
        while(ans.length() < s.length())
        {
            for(int i = 0; i < 26; ++i)
            {
                if(num[i])
                {
                    ans.push_back(i + 'a');
                    num[i]--;
                }
            }
            for(int i = 25; i >= 0; --i)
            {
                if(num[i])
                {
                    ans.push_back(i + 'a');
                    num[i]--;
                }
            }
        }
        return ans;
    }
};