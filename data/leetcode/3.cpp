#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;

class Solution 
{
public:
    //单纯使用set，例如abccabd,就会导致i无意义的从a遍历到c。
    /*
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size();
        set<char> judge;
        int i = 0, j = 0;
        int max_size = 0;
        while(i < len && j < len)
        {
            if(judge.count(s[j]) == 0)
            {
                judge.insert(s[j]);
                ++j;
                max_size = max(max_size, j - i);
            }
            else
            {
                judge.erase(s[i]);
                ++i;
            }
        }
        return max_size;
    }
    */
    /*
    *使用map映射，一次越过无效的区间,这个是自己的思路写出的代码，因为要将之前的map中的元素均删除浪费时间，
    *看了题解之后发现有更方便更快捷的方法，不用进行删除,其实这个删除的思路和上面set好像没啥区别
    */
    /*
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> judge;
        int len = s.size();
        int i = 0, j = 0;
        int max_size = 0;
        int k = 0;
        while(i < len && j < len)
        {
            if(judge.count(s[j]) == 0)
            {
                judge.insert({s[j], j});
                ++j;
                max_size = max(max_size, j - i);
            }
            else
            {
                int deadline = judge[s[j]];
                k = i;
                i = max(i, deadline);
                for(; k <= i; ++k)
                    judge.erase(s[k]);
                judge.insert({s[j], j});
                ++j;   
                ++i;
            }
        }
        return max_size;
    }
    */
    //滑动窗口
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> judge;
        int len = s.size();
        int i = 0, j = 0;
        int max_size = 0;
        for(; j < len; ++j)
        {
            if(judge.count(s[j]))
            {
                i = max(i, judge[s[j]]);
            }
            max_size = max(max_size, j - i + 1);
            judge[s[j]] = j + 1;//用j+1，是为了每次找到重复字符的下一个位置
        }
        return max_size;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution res;
    std::cout << res.lengthOfLongestSubstring(s) << "\n";
}