#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace  std;

int main()
{
    string s = "hello word";
    for(auto a = s.begin(); a != s.end(); ++a)
    {
        std::cout << *a << "\n";
    }
}
