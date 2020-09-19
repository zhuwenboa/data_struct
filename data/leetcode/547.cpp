#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    void dfs(vector<vector<int>>& M, int index, vector<int>& visited)
    {
        for(int j = 0; j < M[0].size(); ++j)
        {
            if(M[index][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                dfs(M, j, visited);
            }
            
        }
    }

    int findCircleNum(vector<vector<int>>& M) 
    {
        vector<int> visited(M.size());
        int count = 0;
        for(int i = 0; i < M.size(); ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                dfs(M, i, visited);
                count++;
            }
        }
        return count;
    }
};