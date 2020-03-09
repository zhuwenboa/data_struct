#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) 
    {
        const int len = s.size();
        if(len == 0) return "";
        if(len == 1) return s;
        vector< vector<bool> > dp(len, vector<bool>(len, false));
        int max_size = 0;
        string max_str = s.substr(0, 1);
        for(int i = 0; i < len; ++i)
        {
            for(int j = i; j >=0; --j)
            {
                if(s[i] == s[j] && ((i - j)< 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if(i - j > max_size)
                    {
                        max_str = s.substr(j, i - j + 1);
                        max_size = i - j;
                    }
                }
            }
        }        
        return max_str;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution res;
    std::cout << res.longestPalindrome(s) << "\n";
}