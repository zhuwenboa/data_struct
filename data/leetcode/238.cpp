#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 


//方法一 时间复杂度O(N)，空间复杂度O(N)
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> res(nums.size());
        for(int i = 1; i < nums.size(); ++i)
        {
            left[i] = nums[i - 1] * left[i - 1];   
        }
        for(int i = nums.size() - 2; i >= 0; --i)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};

//方法二 时间复杂度O(N), 空间复杂度O(1)
class Solution2
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res(nums.size(), 0);
        res[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            res[i] = res[i - 1] * nums[i -1];
        }
        int p = 1;
        for(int i = nums.size() -2; i >= 0; --i)
        {
            p *= nums[i + 1];
            res[i] *= p;   
        }
        return res;
    }
};

int main()
{
    vector<int> vec{1, 2 ,3 ,4};
    Solution2 res;
    vec = res.productExceptSelf(vec);
    for(auto a : vec)
        std::cout << a << "\n";
}