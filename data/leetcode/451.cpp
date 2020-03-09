#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char,int> m;
        for(auto &val:s)
        {
            m[val]++;
        }
        //用priority_queue为map中value-type进行排序，用pair类型。(好方法)
        priority_queue<pair<int,char>>pq;
        for(auto &val:m)
        {
            pq.push( std::make_pair(val.second, val.first) );
        }
        while(!pq.empty())
        {
            auto top = pq.top();
            int num = top.first;
            while(num--)
            {
                res += top.second;
            }
            pq.pop();
        }
        return res;
    }
};