#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution 
{
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        map<char, int> char_s;
        for(char a : chars)
            ++char_s[a];
        int ans = 0;
        for(string s : words)
        {
            map<char, int> word_s;
            bool flag = true;
            for(char a : s)
            {
                ++word_s[a];
                if(char_s[a] < word_s[a])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans += s.size();
        }
        return ans;
    }
};