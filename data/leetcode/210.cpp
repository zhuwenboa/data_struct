#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

//拓扑排序
using namespace std;

class Solution 
{
public:
    //Kahn算法(用的是贪心算法)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        //二维数组当作有向图
        vector<vector<int>> graph; 
        //每个点的权值
        vector<int> weight;
        //存储答案
        vector<int> res;
        graph.resize(numCourses);
        weight.resize(numCourses);

        for(const auto& a : prerequisites)
        {
            //将其存入有向图中
            graph[a[1]].emplace_back(a[0]);
            //将其权值+1
            ++weight[a[0]];
        }
        queue<int> que;
        //将所有入度为0的节点入队
        for(int i = 0; i < weight.size(); ++i)
        {
            if(weight[i] == 0)
                que.push(i);
        }
        while(!que.empty())
        {
            int temp = que.front();
            que.pop();
            res.push_back(temp);
            //将该结点所指向的节点入度-1
            for(int i = 0; i < graph[temp].size(); ++i)
            {
                --weight[graph[temp][i]];
                if(weight[graph[temp][i]] == 0)
                    que.push(graph[temp][i]);
            }
        }
        if(res.size() != numCourses)
            return {};
        return res;
    }
};

//深度优先搜索
class Solution2 
{
public:
    void dfs(int v)
    {
        visited[v] = 1;
        for(const auto& a : graph[v])
        {
            if(visited[a] == 0)
            {
                dfs(a);
                if(invalid)
                    return;
            }
            else if(visited[a] == 1)
            {
                invalid = true;
                return;
            }
        }   
        //将节点标记为已完成
        visited[v] = 2;
        //将节点入栈
        result.emplace_back(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info : prerequisites)
        {
            graph[info[1]].emplace_back(info[0]);
        }        
        for(int i = 0; i < numCourses && !invalid; ++i)
        {
            if(visited[i] == 0)
                dfs(i);
        }
        if(invalid)
            return {};
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
private:
    // 存储有向图
    vector<vector<int>> graph;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool invalid;
};