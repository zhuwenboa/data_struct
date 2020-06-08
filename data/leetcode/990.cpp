#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {
        unordered_multimap<char, char> eq;
        unordered_multimap<char, char> uneq;
        for(auto str : equations)
        {
            if(!str.empty())
            {
                if(str[1] == '=')
                {
                    //eq.insert({str[0], str[3]});
                    auto t  = eq.equal_range(str[0]);
                    for(auto iter = t.first; iter != t.second; ++iter)
                    {
                        eq.insert({iter->second, str[3]});
                    }
                    auto t2 = eq.equal_range(str[3]);
                    for(auto iter = t2.first; iter != t2.second; ++iter)
                    {
                        eq.insert({iter->second, str[0]});
                    }
                    eq.insert({str[0], str[3]});
                }
                else
                {
                    uneq.insert({str[0], str[3]});   
                }
            }
        }
        for(auto a = eq.begin(); a != eq.end(); ++a)
        {
            if(uneq.count(a->first))
            {
                auto t = uneq.equal_range(a->first);
                for(auto iter = t.first; iter != t.second; ++iter)
                {
                    if(iter->second == a->second)
                        return false;
                }
            }
            if(uneq.count(a->second))
            {
                auto t = uneq.equal_range(a->second);
                for(auto iter = t.first; iter != t.second; ++iter)
                {
                    if(iter->second == a->first)
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<string> vec{"a==b", "b==c", "a==c"};
    Solution res;
    std::cout << res.equationsPossible(vec) << "\n";
}