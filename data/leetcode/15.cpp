#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution 
{
public:
    //时间复杂度为O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector< vector<int> > res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end()); //先对数组进行排序
        int i, j, k;                    //定义三个变量
        for(int i = 0; i < nums.size() - 2; ++i) //i作为最外层循环变量，它永远指向最小的数，如果它本身大于0，那就不可能有三个数之和为0的结果。
        {
            if(nums[i] > 0)
                return res;
            if(i >= 1 && nums[i] == nums[i -1]) //防止进行重复判断
                continue;
            j = i + 1;
            k = nums.size() -1;
            while(j < k)
            {
                if( (nums[i] + nums[j] + nums[k]) == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    //下面的两个while循环为了防止出现重复的答案
                    while(nums[j -1] == nums[j] && j < k)  
                        ++j;
                    while(nums[k] == nums[k + 1] && j < k)
                        --k;
                }
                else if( (nums[i] + nums[j] + nums[k]) > 0)
                {
                    --k;
                }
                else 
                {
                    ++j;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> example{-2, 0, 0, 2, 2};
    Solution res;
    auto ans = res.threeSum(example);
    for(auto a : ans)
    {
        for(auto b : a)
            std::cout << b << "\n";
    }
}