#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<functional>

using namespace std;

class Foo 
{
public:
    Foo() : count(0)
    {
    }

    void first(function<void()> printFirst) 
    {
        std::unique_lock<std::mutex> lk(mutex_);
        while(count != 0)
        {
            cond_.wait(lk);
        }                
        ++count;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cond_.notify_all();
        lk.unlock();
    }

    void second(function<void()> printSecond) 
    {
        std::unique_lock<std::mutex> lk(mutex_);
        while(count != 1)
        {
            cond_.wait(lk);
        }
        ++count;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cond_.notify_all();
        lk.unlock();
    }

    void third(function<void()> printThird) 
    {
        std::unique_lock<std::mutex> lk(mutex_);
        while(count != 2)
        {
            cond_.wait(lk);
        }
        count = 0;
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        cond_.notify_all();
        lk.unlock();
    }
private: 
    int count;
    mutable std::mutex mutex_;
    std::condition_variable cond_;
};