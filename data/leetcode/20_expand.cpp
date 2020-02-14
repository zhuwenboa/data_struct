#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

class solution
{
public:  
    void input()
    {
        char a;
        while(std::cin >> a)
        {
            if(a == '0')
                break;
            vec.push_back(a);
        }
    }
    int result()
    {
        int count = 0;
        st.push(1);
        for(auto a = vec.begin(); a != vec.end(); ++a)
        {
            if(*a == '(')
                st.push(*a);
            else if(*a == ')')
            {
                if(st.top() == 1)
                {
                    continue;
                }
                else 
                {
                    count += 2;
                    st.pop();
                }
            }
        }
        return count;
    }

private:  
    std::stack<char> st; 
    std::vector<char> vec;
};

int main()
{
    solution rs;
    rs.input();
    std::cout << rs.result() << "\n";
}