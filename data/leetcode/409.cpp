#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        map<char, int> judge;
        int sum = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            ++judge[s[i]];
        }        
        for(auto a : judge)
        {
            sum += a.second / 2 * 2; //贪心算法，因为只能有一个出现次数为奇数次的当作回文串的中心，所以我们都加入其出现次数的偶数次
        }
        if(sum < s.size() && (sum % 2 == 0))
            sum += 1;
        return sum;
    }
};