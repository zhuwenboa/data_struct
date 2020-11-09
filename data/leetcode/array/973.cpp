#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>

using namespace std;


struct compare 
{
    bool operator () (const pair<double, int>& a, const pair<double, int>& b)
    {
        return a.first < b.first;
    }
};

class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        set<pair<double, int>, compare> judge;
        int count = 0;
        vector<vector<int>> ans;
        for(auto vec : points)
        {
            double distance = sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
            judge.insert({distance, count});
            ++count;
        }
        auto iter = judge.begin();
        for(int i = 0; i < K && iter != judge.end(); ++i)
        {
            ans.emplace_back(points[iter->second]);
            ++iter;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> vec {{1, 2}, {2, 3}};
    Solution res;
    vec = res.kClosest(vec, 2);
    for(auto a : vec)
    {
        std::cout << "[" << a[0] << "," << a[1] << "]\n";
    }
}
