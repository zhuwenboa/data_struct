#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        deque<pair<int, int>> q_;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!q_.empty() && q_.front().second <= i-k)
                q_.pop_front();
            while(!q_.empty() && q_.back().first <= nums[i])
                q_.pop_back();
            q_.push_back({nums[i], i});
            if(i >= k-1)
                ans.push_back(q_.front().first);
        }
        return ans;
    }
};