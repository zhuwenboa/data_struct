#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache 
{
public:
    struct Value  
    {
        Value(int a, int b) : key(a), value(b) {}
        int key;
        int value;
    };
    LRUCache(int capacity) 
    {
        capacity_ = capacity;
        count_ = 0;
        Value_.clear();
        I_map.clear();
    }
    
    int get(int key) 
    {
        int res = -1;
        if(I_map.count(key))
        {
            list<Value>::iterator iter = I_map[key];
            res = iter->value;
            Value_.erase(iter);
        }
        else    
        {
            return res;
        }
        Value_.push_front({key, res});
        I_map[key] = Value_.begin();
        return res;
    }
    
    void put(int key, int value) 
    {
        if(I_map.count(key))
        {
            list<Value>::iterator iter = I_map[key];
            Value_.erase(iter);
            Value_.push_front({key, value});
            I_map[key] = Value_.begin();
            return;
        }
        if(count_ == capacity_)
        {
            auto iter = Value_.back();
            I_map.erase(iter.key);
            Value_.pop_back();
            count_--;
        }
        Value_.push_front({key, value});
        I_map[key] = Value_.begin();
        count_++;
    }
private:  
    int capacity_;
    int count_;
    list<Value> Value_;
    unordered_map<int, list<Value>::iterator> I_map;
};