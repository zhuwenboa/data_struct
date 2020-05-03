#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//回文数
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int reverte = 0;
        while (x > reverte)
        {
            reverte = reverte * 10 + x % 10;
            x /= 10;
        }
        return x == reverte || x == reverte / 10;
    }
};

int main()
{
    int x = 12121;
    Solution res;
    cout << res.isPalindrome(x) << "\n";
}