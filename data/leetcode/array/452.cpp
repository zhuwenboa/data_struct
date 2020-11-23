#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
开始我的思路是类似于合并区间的想法： 
    将points[0]进行排序，然后再进行区间合并，合并为小区间，依次类推，合并到最后剩几个区间就需要射几次箭。
    这个思路是开始，但感觉相对麻烦。
然后去看了题解： 用的方法为 排序+贪心。对points[1]进行排序就很巧妙的解决了这个问题。
    对poinst进行遍历，如果最左侧元素值大于当前最右侧元素值证明需要另外一次射箭。
*/

class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), 
            [&](const vector<int>& a, const vector<int>& b)
            {
                return a[1] < b[1];
            }
        );
        int pos_val = points[0][1];
        int ans = 1;
        for(const auto& t : points)
        {
            if(t[0] > pos_val)
            {
                pos_val = t[1];
                ans++;
            }
        }
        return ans;
    }
};