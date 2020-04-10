#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

//c++ 状态机和栈
class Solution 
{
public:
    enum status
    {
        TAIL,
        MID 
    };
    string reverseWords(string s) 
    {
        string res;
        status st = TAIL;
        stack<char> bucket;        
        for(int i = s.size() -1; i >= 0; --i)
        {
            if(st == TAIL && s[i] == ' ')
            {
                continue;
            }
            if(st == TAIL)
                st = MID;
            if(s[i] != ' ')  
            {
                bucket.push(s[i]);
                continue;
            }
            while(!bucket.empty())
            {
                res.push_back(bucket.top());
                bucket.pop();
            }
            if(s[i] == ' ' && i - 1 >= 0)
            {
                if(s[i -1] == ' ')
                    continue;
                else
                    res.push_back(s[i]);
            }   
        }
        while(!bucket.empty())
        {
            res.push_back(bucket.top());
            bucket.pop();
        }
        return res;
    }
};
//用sstream流来进行字符串的转换
class Solution2 {
public:
    string reverseWords(string s) 
    {
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+temp+ans;
        }
        if(ans!="")
            ans.erase(ans.begin());
        return ans; 
    }
};

int main()
{
    string s("the sky is blue");
    Solution res;
    Solution2 res2;
    std::cout <<  res2.reverseWords(s) << "1" << "\n";
}