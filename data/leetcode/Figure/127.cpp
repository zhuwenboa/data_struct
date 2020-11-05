#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution 
{
public:
    void addWord(const string& word)
    {
        if(!wordId.count(word))
        {
            wordId[word] = numId++;
            edge.emplace_back();
        }
    }
    //构建图
    void addEdge(string word)
    {
        addWord(word);
        int id1 = wordId[word];
        for(char& a : word)
        {
            char tmp = a;
            a = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].emplace_back(id2);
            edge[id2].emplace_back(id1);
            a = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        for(auto a : wordList)
        {
            addEdge(a);
        }
        addEdge(beginWord);
        if(!wordId.count(endWord))
            return 0;
        int beginId = wordId[beginWord];
        int endId = wordId[endWord];
        vector<int> dis(numId, INT32_MAX);
        queue<int> que;
        dis[beginId] = 0;
        que.push(beginId);
        while(!que.empty())
        {
            int curId = que.front();
            que.pop();
            if(curId == endId)
            {
                return dis[endId] / 2 + 1;
            }
            //当前ID对应的边去查找
            for(int &it : edge[curId])
            {
                if(dis[it] == INT32_MAX)
                {
                    dis[it] = dis[curId] + 1;
                    que.push(it);
                }
            }
        }
        return 0;   
    }

private:   
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int numId = 0;
};