#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<queue>

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

struct compare 
{
    bool operator() (const int& a, const int& b)
    {
        return a > b;
    }
};

class MedianFinder2 
{
public:
    /** initialize your data structure here. */
    MedianFinder2() 
    {
        count_ = 0;
    }
    
    void addNum(int num) 
    {
        ++count_;
        if(count_ == 1)
        {
            max_heap_.push(num);
            return;
        }
        if(count_ % 2 == 1)
        {
            if(num > min_heap_.top())
            {
                max_heap_.push(min_heap_.top());
                min_heap_.pop();
                min_heap_.push(num);
            }
            else 
                max_heap_.push(num);
        }
        else 
        {
            if(num < max_heap_.top())
            {
                min_heap_.push(max_heap_.top());
                max_heap_.pop();
                max_heap_.push(num);
            }            
            else 
                min_heap_.push(num);
        }
    }
    
    double findMedian() 
    {
        if(count_ % 2 == 1)
            return static_cast<double>(max_heap_.top());
        else 
        {
            double l_mid = max_heap_.top();
            double r_mid = min_heap_.top();
            return (l_mid + r_mid) / 2;
        }
    }
private:  
    std::priority_queue<int> max_heap_;
    std::priority_queue<int, vector<int>, compare> min_heap_;
    int count_;    
};

int main()
{
    MedianFinder2 res;
    res.addNum(1);
    std::cout << res.findMedian() << "\n";
    res.addNum(2);
    res.addNum(3);
    res.addNum(4);
    //std::cout << res.sum << "\n";
    std::cout << res.findMedian() << "\n";
}

