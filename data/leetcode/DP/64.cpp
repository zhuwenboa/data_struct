#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); ++i)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
            //std::cout << dp[i][0] << "  ";
        }
        //std::cout << "\n";
        for(int i = 1; i < grid[0].size(); ++i)
        {
            dp[0][i] = grid[0][i] + dp[0][i-1];
            std::cout << dp[0][i] << "  ";
        }
        //std::cout << "\n";
        for(int i = 1; i < grid.size(); ++i)
        {
            for(int j = 1; j < grid[0].size(); ++j)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                //std::cout <<  dp[i][j] << "   ";
            }
            //std::cout << "\n";
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    vector<vector<int>> vec{{1,2,5},{3,2,1}};
    Solution res;
    std::cout << res.minPathSum(vec) << "\n";
}