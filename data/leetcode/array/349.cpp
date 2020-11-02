#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_map<int, int> judge;
        for(int i = 0; i < nums1.size(); ++i)
        {
            judge[nums1[i]]  = 1;
        }
        for(int i = 0; i < nums2.size(); ++i)
        {
            if(judge[nums2[i]] == 1)
            {
                ++judge[nums2[i]];
                ans.emplace_back(nums2[i]);
            }
        }
        return ans;
    }
};