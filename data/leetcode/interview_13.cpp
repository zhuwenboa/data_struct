#include<iostream>
#include<algorithm>
#include<vector>
#include<set> 
#include<stack>
using namespace std;
//题目:机器人的运动范围
//dfs
class Solution 
{
public:
    int movingCount(int m, int n, int k) 
    {
        int ans = 0;
        if(k >= 0)
            dfs(0, 0, m, n, k, ans);
        return ans;
    }
    void dfs(int x, int y, int m, int n, int k, int& ans)
    {
        ++ans;
        judge.insert({x, y});
        for(int i = 0; i < 4; ++i)
        {
            int temp_x = x + dir_x[i];
            int temp_y = y + dir_y[i];
            if(temp_x < 0 || temp_x >= m || temp_y < 0 || temp_y >= n || judge.count({temp_x, temp_y}))
                continue;
            int sum_xy = 0;
            sum_xy += temp_x / 10;
            sum_xy += temp_x % 10;
            sum_xy += temp_y / 10;
            sum_xy += temp_y % 10;
            if(sum_xy > k)
                continue;
            dfs(temp_x, temp_y, m, n, k, ans);
        }
    }
    vector<int> dir_x{1, 0, -1, 0};
    vector<int> dir_y{0, 1, 0, -1};
    set<pair<int, int>> judge;
};

//bfs
class Solution2 {
public:
    int movingCount(int m, int n, int k) 
    {
        if(k < 0)
            return 0;
        vector<int> dir_x {1, 0};
        vector<int> dir_y {0, 1};
        stack<pair<int, int>> st;
        set<pair<int, int>> judge;
        int ans  = 0;
        st.push({0, 0});
        while(!st.empty())
        {
            pair<int, int> coordinate  = st.top();
            st.pop();
            ++ans;
            judge.insert(coordinate);
            for(int i = 0; i < 2; ++i)
            {
                int temp_x = coordinate.first + dir_x[i];
                int temp_y = coordinate.second + dir_y[i];
                if(temp_x < 0 || temp_x >= m || temp_y < 0 || temp_y >= n || judge.count({temp_x, temp_y}))
                    continue;
                int sum_xy = 0;
                sum_xy += temp_x / 10;
                sum_xy += temp_x % 10;
                sum_xy += temp_y / 10;
                sum_xy += temp_y % 10;
                if(sum_xy > k)
                    continue;
                st.push({temp_x, temp_y});
            }
        }    
        return ans;           
    }
};

int main()
{
    Solution2 res;
    std::cout << res.movingCount(3, 2, 17) << "\n";
}