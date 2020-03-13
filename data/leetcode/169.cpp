#include<iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        map<int, int> judge;
        for(int i = 0; i < nums.size(); ++i)
        {
            ++judge[nums[i]];
            if(judge[nums[i]] > nums.size() / 2)
                return nums[i];
        }
        return 0;
    }
};

int main()
{
    vector<int> vec{3, 2, 3};
    Solution res;
    std::cout << res.majorityElement(vec) << "\n";
}