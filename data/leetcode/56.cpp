#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        int j = 0;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(res[j][1] >= intervals[i][0] && res[j][0] <= intervals[i][1])
            {
                int left = min(res[j][0], intervals[i][0]);
                int right = max(res[j][1], intervals[i][1]);
                res[j][0] = left;
                res[j][1] = right;
            }       
            else
            {
                res.push_back({intervals[i][0], intervals[i][1]});
                ++j;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vec{{5,5},{1,2},{2,4},{2,3},{4,4},{5,5},{2,3},{5,6},{0,0},{5,6}};
    Solution res;
    vec = res.merge(vec);
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[0].size(); ++j)
            std::cout << vec[i][j] << "  ";
        std::cout << "\n";
    }
}