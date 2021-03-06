#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    用双指针法 时间复杂度O(N) 空间复杂度O(1)
*/

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int left_index = 0;
        int right_index = height.size() -1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while(left_index <= right_index)
        {
            //如果左端最大值小于右端最大值，则用左端最大值
            if(left_max < right_max)
            {
                ans += max(left_max - height[left_index], 0);
                left_max = max(left_max, height[left_index]);
                left_index++;
            }
            else 
            {
                ans += max(right_max - height[right_index], 0);
                right_max = max(right_max, height[right_index]);
                right_index--;
            }
        }
        return ans;
    }
};


/*
    用两个临时数组保存当前节点的左端最大值和右端最大值
    时间复杂度为O(N), 空间复杂度为O(N)
*/
class Solution2 
{
public:
    int trap(vector<int>& height) 
    {
        if(height.size() <= 1)
            return 0;
        vector<int> left_high(height.size());
        vector<int> right_high(height.size());
        left_high[0] = height[0];
        right_high[height.size()-1] = height[height.size()-1];
        int ans = 0;
        for(int i = 1; i < height.size(); ++i)
        {
            left_high[i] = max(left_high[i-1], height[i]);
        }
        for(int i = height.size()-2; i >= 0; --i)
        {
            right_high[i] = max(right_high[i+1], height[i]);
        }
        for(int i = 0; i < height.size(); ++i)
        {
            int max_left = left_high[i];
            int max_right = right_high[i];
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};