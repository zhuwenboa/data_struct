#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution
{
public:   
    void sort(vector<int>& vec)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            int t = vec[i];
            int j = i - 1;
            for(; j >= 0; --j)
            {
                if(vec[j] > t)
                    vec[j+1] = vec[j];
                else 
                {
                    break;
                }
            }
            vec[j+1] = t;
        }
    }
};

int main()
{
    vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution res;
    res.sort(vec);
    for(const int& a : vec)
    {
        std::cout << a << "\t";
    }
    std::cout << std::endl;
}