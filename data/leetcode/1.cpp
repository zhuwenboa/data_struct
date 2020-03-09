#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> judge;
        //一致哈希算法
        for(int i = 0; i < nums.size(); ++i)
        {
            if(judge.count(target - nums[i]) == 0)
            {
                judge[nums[i]] = i;
            }
            else
            {
                return{judge[target - nums[i]], i};
            }
        }        
        return nums;
    }
};

int main()
{
    Solution res;
    vector<int> vec{2, 7, 11, 15};
    vector<int> temp = res.twoSum(vec, 18);
    for(auto a : temp)
        std::cout << a << "\n";
}