#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int max_len = 0;
        int count = 0;
        mp.insert({0, -1});
        for(int i = 0; i < nums.size(); ++i)
        {
            count += (nums[i] == 1 ? 1 : -1);
            if(mp.count(count))
            {
                max_len = max(max_len, i - mp[count]);
            }
            mp.insert({count, i});
        }
        return max_len;
    }
};