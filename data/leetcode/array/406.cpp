#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [&](const vector<int>& a, const vector<int>& b)
        {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans(people.size());
        for(auto tmp : people)
        {
            int space = tmp[1] + 1;
            for(int i = 0; i < people.size(); ++i)
            {
                if(ans[i].empty())
                    --space;
                if(!space)
                {
                    ans[i] = tmp;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> people{{5,1}, {4,4}, {6,1}, {5,0}, {7,0}, {7,1}};
    Solution res;
    res.reconstructQueue(people);
}