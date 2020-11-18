#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        vector<int> distance(n, 0);
        for(int i = 0; i < n; ++i)
        {
            distance[i] = gas[i] - cost[i];
        }
        for(int i = 0; i < n; ++i)
        { 
            int cur_oil = distance[i];
            if(cur_oil < 0)
                continue;
            int cur = (i+1) % n;
            bool flag = true;
            for(int j = n - 1; j > 0; --j, ++cur)
            {
                if(cur >= n)
                    cur %= n;
                if(cur_oil + distance[cur] < 0)
                {
                    flag = false;
                    break;
                }
                cur_oil += distance[cur];
            }
            if(flag == true)
                return i;
        }
        return -1;
    }
};