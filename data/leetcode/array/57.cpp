#include<iostream>
#include<vector>
#include<algorithm>
#include<set>


using namespace std;
/*
class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        set<int> val;
        for(auto a : intervals)
        {
            int pre = a[0];
            int end = a[1];
            for(int i = pre; i <= end; ++i)
                val.insert(i);
        }
        {
            int new_pre = newInterval[0];
            int new_end = newInterval[1];
            for(int i = new_pre; i <= new_end; ++i)
                val.insert(i);
        }
        bool new_int = true;
        int pre;
        int start;
        int end;
        for(auto a = val.begin(); a != val.end(); ++a)
        {
            if(new_int)
            {
                start = *a;
                end = *a;
                pre = *a;
                new_int = false;
            }
            else 
            {
                if(*a == pre+1)
                {
                    end = *a;
                    pre = *a;
                    continue;           
                }            
                else 
                {
                    ans.push_back({start, end});
                    start = *a;
                    end = *a;
                    pre = *a;
                }    
            }
        }
        return ans;
    }
};
*/

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) 
        {
            if (interval[0] > right) 
            {
                // 在插入区间的右侧且无交集
                if (!placed) 
                {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) 
            {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else 
            {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) 
        {
            ans.push_back({left, right});
        }
        return ans;
    }
};
