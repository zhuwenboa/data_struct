#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Automaton 
{
    string state = "start";
    unordered_map<string, vector<string>> table = 
    {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) 
    {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) 
    {
        state = table[state][get_col(c)];
        if (state == "in_number") 
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT32_MAX) : min(ans, -(long long)INT32_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution 
{
public:
    int myAtoi(string str) 
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

/*
class Solution 
{
public:
    int myAtoi(string s) 
    {
        long long ans = 0;
        int flag = 0;
        for(const char& a : s)
        {
            if(a == '-' && flag == 0)
                flag = 1;
            if(a < '0' && a > '9')
                continue;
            if(a >= '0' && a <= '9')
            {
                if(flag == 0)
                    flag = 2;
                ans *= 10;
                ans += a - '0';

                ans = flag == 1 ? min(ans, -(long long)INT32_MIN) : min(ans, (long long)INT32_MAX);
            }
        }
        if(flag == 1)
            ans *= -1;
        return static_cast<int>(ans);
    }
};
*/