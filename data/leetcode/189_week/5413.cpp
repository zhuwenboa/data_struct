#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<sstream>
#include<string>
using namespace std;

class Solution 
{
public:
    struct node 
    {
        int len;
        int index;
        string s;
        bool operator < (const node& a) const
        {
            if(len == a.len)
                return index < a.index;
            else 
                return len < a.len;
        }
    };
    string arrangeWords(string text) 
    {
        set<node> judge;
        stringstream in;
        in << text;
        string word;  
        int index = 0;      
        while(in >> word)
        {
            if(index == 0)
                word[0] += 32;
            judge.insert({static_cast<int>(word.size()), index, word});
            ++index;
        }           
        string res;
        auto first = judge.begin();
        string fi = first->s;
        if(fi[0] >= 61)
            fi[0] -= 32;
        res += fi;
        for(auto a = ++first; a != judge.end(); ++a)
        {
            res += " ";
            res += a->s;
        }
        return res;
    }
};

int main()
{
    string text = "keep calm and code on";
    Solution res;
    std::cout << res.arrangeWords(text) << "\n";
}