#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;

class Solution {
public:

    struct water
    {
        water(int a, int b) : x(a), y(b) {}
        int x;
        int y;
    };

    bool canMeasureWater(int x, int y, int z) 
    {
        return bfs(x, y, z);
    }
    bool bfs(int x, int y, int z)
    {
        queue<water> que;
        que.push({0, 0});
        set<pair<int, int> >judge;
        while(!que.empty())
        {
            water temp = que.front();
            que.pop();
            if(temp.x == z || temp.y == z || (temp.x + temp.y) == z)     
                return true;
            if(judge.count({temp.x, temp.y}) != 0)
                continue;
            judge.insert({temp.x, temp.y});
            //y->x
            if(temp.x < x && temp.y > 0)
            {
                //倒满x, y还有剩余
                if( (temp.y + temp.x) > x)
                {
                    que.push({x, temp.y-(x - temp.x)});
                }
                //倒完之后y无剩余
                else
                {
                    que.push({temp.x + temp.y, 0});                       
                }
            }
            //x->y
            if(temp.x > 0 && temp.y < y)
            {
                //倒满y，x还有剩余
                if((temp.y + temp.x) > y)
                {
                    que.push({temp.x - (y - temp.y), y});
                }
                else
                {
                    que.push({0, temp.x + temp.y});
                }
            }
            //向x中倒满液体
            if(temp.x < x)
                que.push({x, temp.y});
            //向y中倒满液体
            if(temp.y < y)
                que.push({temp.x, y});
            //清空x中的液体
            if(temp.x > 0)
                que.push({0, temp.y});
            //清空y中的液体
            if(temp.y > 0)
                que.push({temp.x, 0});
        }
        return false;
    }

};

int main()
{
    Solution res;
    std::cout << res.canMeasureWater(3, 5, 4) << "\n";
}