#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:   
    vector<int> sort(vector<int>& vec)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            for(int j = i + 1; j < vec.size(); ++j)
            {
                if(vec[i] > vec[j])
                    swap(vec[i], vec[j]);
            }
        }
        return vec;
    }
};

int main()
{
    vector<int> vec{9, 8, 7, 6, 5, 4, 3, 2, 1};
    Solution res;
    vec = res.sort(vec);
    for(const int& a : vec)
    {
        std::cout << a << "\t";
    }
    std::cout << std::endl;
}