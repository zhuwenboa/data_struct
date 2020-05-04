#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


class Solution 
{
public:
    //回溯，将所有可能遍历一遍找到最小值,对回溯法进行标记优化 最后一个例子超时未通过
    void huisu(vector<int>& nums, int x, int l, int& step)
    {
        if(judge.count({x, l}))
            return;
        if(x >= nums.size()-1)
        {
            step = min(step, l);
            return;
        }
        for(int i = 1; i <= nums[x]; ++i)
        {
            huisu(nums, x+i, l+1, step);
            judge.insert({x+i, l+1});
        }
    } 

    int jump(vector<int>& nums) 
    {
        int step = INT32_MAX;
        huisu(nums, 0, 0, step);
        return step;
    }
private:  
    set<pair<int, int>> judge;    
};

//贪心算法
class Solution2
{
public:
    int jump(vector<int>& nums) 
    {
        int m_pos = 0, end = 0, step = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            //找到每一个位置可以跳跃的最远距离
            if(m_pos >= i)
                m_pos = max(m_pos, i + nums[i]);
            if(i == end)
            {
                end = m_pos;
                ++step;
            }
        }
        return step;       
    }
};

int main()
{
    Solution res;
    vector<int> vec {2, 3, 1, 1, 4};
    std::cout << res.jump(vec) << "\n";
}