#include<iostream>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int fib(int n) 
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int ans = 0;
        int n1 = 0;
        int n2 = 1;
        for(int i = 1; i < n; ++i)
        {
            ans = (n1 + n2) % 1000000007;
            n1 = n2;
            n2 = ans;
        }
        return ans;
    }
};
