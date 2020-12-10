#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        vector<int> coin(2, 0);
        for(int i = 0; i < bills.size(); ++i)
        {
            if(bills[i] == 5)
            {
                coin[0]++;
            }
            else if(bills[i] == 10)
            {
                if(coin[0] == 0)
                    return false;
                else 
                {
                    coin[0]--;
                    coin[1]++;
                }
            }
            else 
            {
                if(coin[1] != 0 && coin[0] != 0)
                {
                    coin[0]--;
                    coin[1]--;
                }
                else if(coin[0] >= 3)
                {
                    coin[0] -= 3;
                }
                else 
                    return false;
            }
        }
        return true;
    }
};