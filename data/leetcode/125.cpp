#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        int i = 0, j = s.size() -1;
        while(i < j)
        {
            while( !( ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')) || (s[j] >= '0' && s[j] <= '9')) )
            {
                if(i >= j)
                    return true;
                --j;
            }
            while( !( ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) || (s[i] >= '0' && s[i] <= '9') ) )
            {
                if(i >= j)
                    return true;
                ++i;
            }
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            std::cout << "s[i] = " << s[i] << "\n";
            std::cout << "s[j] = " << s[j] << "\n";
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    //实现转换小写函数
    char tolower(char c)
    {
        if(c >= 'A' && c <= 'Z')
        {
            c = c + ('a' - 'A');
        }
        return c;
    }
};

int main()
{
    string s = "1p";
    Solution res;
    std::cout << res.isPalindrome(s) << "\n";
}