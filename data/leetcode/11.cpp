#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution1
{
public:
    //暴力法 时间复杂度O(n^2)
    int maxArea(vector<int>& height) 
    {
        int maxSize = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            for(int j = height.size()-1; j > i; --j)
            {
                maxSize = max(maxSize, (j - i)* min(height[i], height[j]));
            }
        }   
        return maxSize;
    }
};

//双指针法 时间复杂度O(n)
class Solution2
{
public:
    int maxArea(vector<int>& height) 
    {
        int maxSize = 0; 
        int head = 0;
        int last = height.size()-1;
        bool flag= true;
        while(flag)
        {
            maxSize = max(maxSize, (last-head)*min(height[head], height[last]));
            if(height[head] > height[last])
            {
                flag = false;
                for(int i = last-1; i > head; --i)
                {
                    if(height[i] > height[last])
                    {
                        last = i;
                        flag = true;
                        break;
                    }
                }
            }
            else
            {
                flag = false;
                for(int i = head+1; i < last; ++i)
                {
                    if(height[i] > height[head])
                    {
                        head = i;
                        flag = true;
                        break;
                    }
                }
            }
            
        }
        return maxSize;
    }
};