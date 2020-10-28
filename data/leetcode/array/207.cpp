#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        if(arr.size() == 0)
            return false;
        unordered_map<int, int> map_;
        vector<bool> judge(1000, true);
        for(int a : arr)
        {
            map_[a]++;
        }
        for(auto t : map_)
        {
            if(judge[t.second] == false)
                return false;
            judge[t.second] = false;
        }
        return true;
    }
};