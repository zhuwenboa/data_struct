#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

class Solution 
{
public:
    int myAtoi(string str) 
    {
        int sum = 0;
        for(int i = 0; i <str.size(); ++i)
        {
            if(str[i] == ' ')
                continue;
            else
            {
                if(str[i] == '-')
                {
                    int count = 0;
                    int j = i + 1;
                    while(j < str.size() && str[j] >= '0' && str[j] <= '9')
                    {
                        if(count != 0)
                        {
                            int a = (INT32_MIN+1) / count;
                            if(a < 10)
                                return INT32_MIN;
                            if(a == 10)
                            {
                                if(count * 10 - INT32_MIN < (str[j] - 48))
                                    return INT32_MIN;
                            }
                        }
                        count *= 10;
                        count -= (str[j] -48);
                        ++j;
                    }
                    return count;
                }
               else if(str[i] == '+')
                {
                    int count = 0;
                    int j = i + 1;
                    while(j < str.size() && str[j] >= '0' && str[j] <= '9')
                    {
                        if(count != 0)
                        {
                            int a = INT32_MAX / count;
                            if(a < 10)
                                return INT32_MAX;
                            if(a == 10)
                            {
                                if(INT32_MAX - count * 10 < (str[j] - 48))
                                    return INT32_MAX;
                            }
                        }
                        count *= 10;
                        count += (str[j] - 48);
                        ++j;
                    }
                    return count;
                }
                else if(str[i] >= '0' && str[i] <= '9')
                {
                    int count = str[i] -48;
                    int j = i + 1;
                    while(j < str.size() && str[j] >= '0' && str[j] <= '9')
                    {
                        if(count != 0)
                        {
                            int a = INT32_MAX / count;
                            if(a < 10)
                                return INT32_MAX;
                            if(a == 10)
                            {
                                if(INT32_MAX - count * 10 < (str[j] - 48))
                                    return INT32_MAX;
                            }
                        }
                        count *= 10;
                        count += (str[j] -48);
                        ++j;
                    }
                    return count;
                }
                else
                {
                    return 0;
                }
            }
        }    
        return 0;    
    }
};

int main()
{
    string s("2147483646");
    Solution res;
    int a = res.myAtoi(s);
    std::cout << a << "\n";
}