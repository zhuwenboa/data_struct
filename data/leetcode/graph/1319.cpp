#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> graph;
    vector<bool> used;
public:  
    int makeConnected(int n, vector<vector<int>>& connections) 
    {  
        //整数减去无符号整数会自动转换为无符号整数，所以要进行强制转换 
        if(n - static_cast<int>(connections.size()) > 1)
            return -1;
        graph.resize(n);
        used.resize(n, false);
        int ans = 0;
        for(int i = 0; i < connections.size(); ++i)
        {
            graph[connections[i][0]].emplace_back(connections[i][1]);
            graph[connections[i][1]].emplace_back(connections[i][0]);
        }
        for(int i = 0; i < n; ++i)
        {
            if(!used[i])
            {
                dfs(i);
                ++ans;
            }
        }
        return ans - 1;
    }
    void dfs(int v)
    {
        used[v] = true;
        for(int t : graph[v])
        {
            if(!used[t])
                dfs(t);
        }        
    }
};