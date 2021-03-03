#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    string frequencySort(string s) 
    {
        if(s.empty())
            return "";
        unordered_map<char, int> hash_;
        priority_queue<pair<int, char>> que_;
        string ans;
        for(const char& a : s)
        {
            hash_[a]++;
        }
        for(auto a = hash_.begin(); a != hash_.end(); ++a)
        {
            que_.push({a->second, a->first});
        }
        while(!que_.empty())
        {
            int count = que_.top().first;
            while(count--)
                ans += que_.top().second;
            que_.pop();
        }
        return ans;
    }
};