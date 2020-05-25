#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>

using namespace std;

class LRUCache 
{
public:
    LRUCache(int capacity) : capacity_(capacity)
    {
    }
    
    int get(int key) 
    {
        if(iter_table.count(key) == 0)
            return -1;
        auto iter = iter_table[key];
        Value temp = *iter;
        data_table.erase(iter);
        iter_table.erase(key);
        data_table.push_front({temp});
        iter_table.insert({key, data_table.begin()});
        return temp.value;   
    }
    
    void put(int key, int value) 
    {
        if(capacity_ == 0)
            return;
        auto iter = iter_table.find(key);
        //要插入新的数据
        if(iter == iter_table.end())
        {
            //缓存已满
            if(static_cast<int>(iter_table.size()) == capacity_)
            {
                //删除最不常使用的元素
                auto it = data_table.back();
                iter_table.erase(it.key);
                data_table.pop_back();      
            }
            data_table.push_front({key, value});
            iter_table.insert({key, data_table.begin()});
        }
        //插入的数据在集合中已有
        else 
        {
            auto iter = iter_table[key];
            data_table.erase(iter);
            iter_table.erase(key);
            data_table.push_front({key, value});
            iter_table.insert({key, data_table.begin()});
        }
    }
private:  
    struct Value 
    {
        Value(int key_, int value_) :  key(key_), value(value_)
        {}
        int key, value;
    };
    unordered_map<int, list<Value>::iterator> iter_table;
    list<Value> data_table;
    const int capacity_;
};