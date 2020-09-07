#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

class compare
{
public: 
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> record;
        for(int& a : nums)
        {
            record[a]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        for(auto& tmp : record)
        {
            if(que.size() == k)
            {
                if(que.top().second < tmp.second)
                {
                    que.pop();
                    que.emplace(tmp);
                }
            }
            else   
            {
                que.emplace(tmp);
            }
        }
        vector<int> res;
        while(!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        return res;   
    }
};

int main()
{
    vector<int> vec{1,1,1,2,2,3};
    Solution res;
    vec = res.topKFrequent(vec, 2);
    for(auto& a : vec)
        std::cout << a << "\n";
}