#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

class MedianFinder 
{
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        sum = 0;
    }
    
    void addNum(int num) 
    {
        ++sum;
        std::list<int>::iterator iter = cont_.begin();
        for(; iter != cont_.end(); ++iter)
        {
            if(*iter >= num)
                break;
        }
        if(iter == cont_.end())
        {
            cont_.push_back(num);
            return;
        }
        cont_.insert(iter, num);
    }
    
    double findMedian() 
    {
        if(sum == 0)
            return -1;
        if(sum % 2 == 0)
        {
            int tmp = sum / 2;
            double l_val, r_val;
            std::list<int>::iterator iter = cont_.begin();
            for(int i = 0; i < tmp -1; ++i)
                ++iter;
            l_val = *iter;
            ++iter;
            r_val = *iter;
            return (l_val + r_val) / 2;
        }
        else 
        {
            int tmp = sum / 2;
            std::list<int>::iterator iter = cont_.begin();
            for(int i = 0; i < tmp; ++i)
                ++iter;
            return static_cast<double>(*iter);
        }
    }
private: 
    std::list<int> cont_;
    int sum;
};

int main()
{
    MedianFinder res;
    res.addNum(1);
    std::cout << res.findMedian() << "\n";
    res.addNum(2);
    res.addNum(3);
    //std::cout << res.sum << "\n";
    std::cout << res.findMedian() << "\n";
}

