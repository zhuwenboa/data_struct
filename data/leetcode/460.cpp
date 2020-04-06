#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<list>
//LFU缓存
using namespace std;

/*
    哈希表map+平衡二叉树(红黑树 set)实现的LFU缓存
    put和get的时间复杂度均为O(logN),操作的时间复杂度瓶颈就在于平衡二叉树的插入删除时间均为O(logN)。
*/

class LFUCache_Set_Table 
{
public:
    LFUCache_Set_Table(int capacity_) 
    : capacity(capacity_),
    time(0) 
    {}
    
    int get(int key) 
    {
        if(capacity == 0)
            return -1;
        auto it = table.find(key);
        if(it == table.end())
            return -1;
        Value cache = it->second;
        judge.erase(cache);
        cache.count++;
        cache.time = ++time;
        judge.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) 
    {
        if(capacity == 0)
            return;
        auto it = table.find(key);
        if(it == table.end())
        {
            if(table.size() == capacity)
            {
                //先将不活跃的元素删除
                table.erase(judge.begin()->key);
                judge.erase(judge.begin());
            }
            Value put_(0, ++time, key, value);
            table[key] = put_;
            judge.insert(put_);
        }
        else
        {
            Value temp = it->second;
            judge.erase(temp);
            Value put_(temp.count+1, ++time, key, value);
            table[key] = put_;
            judge.insert(put_);
        }
    }

private:  
    const int capacity;
    int time;
    struct Value
    {   
        Value(int count_, int time_, int key_, int value_)
         : count(count_), 
           time(time_),
           key(key_), 
           value(value_) {}
        bool operator < (const Value& a) const 
        {
            return count == a.count ? time < a.time : count < a.count;
        }
        int key;
        int value;
        int count;
        int time;
    };
    unordered_map<int, Value> table;
    set<Value> judge;
};


/*
    使用双哈希表和双向链表来设计数据结构。
    插入删除都是O(1)
*/
class LFUCache_Double_Table
{
public:
    LFUCache_Double_Table(int capacity_) 
        : capacity(capacity_), 
          minfreq(0)    
    {
        iter_table.clear();
        freq_table.clear();
    }
    
    int get(int key) 
    {
        if(capacity == 0)
            return -1;
        auto it = iter_table.find(key);
        if(it == iter_table.end())
            return -1;
        list<Value>::iterator iter = it->second;
        //在此处一定要先存储iter的值，因为在下面删除list中的结点iter时会导致iter迭代器失效
        int value = iter->value;
        int freq = iter->freq;
        Value new_node(key, value, freq +1);
        //删除iter->freq中key对应的元素,此处操作会导致迭代器iter失效
        freq_table[freq].erase(iter);
        if(freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);
            if(minfreq == freq)
                minfreq += 1;
        }
        freq_table[freq+1].push_front(new_node);
        iter_table[key] = freq_table[freq+1].begin();
        return new_node.value;
    }
    
    void put(int key, int value) 
    {
        if(capacity == 0)
            return;
        auto it = iter_table.find(key);
        if(it == iter_table.end())
        {
            //元素已满
            if(iter_table.size() == capacity)
            {
                auto it2 = freq_table[minfreq].back();
                iter_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if(freq_table[minfreq].size() == 0)
                {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Value{key, value, 1});
            iter_table[key] = freq_table[1].begin();
            minfreq = 1;
        } 
        else
        {
            list<Value>::iterator iter = it->second;
            //创建新元素
            int freq = iter->freq;
            Value new_node(iter->key, value, freq +1);
            //将freq_table中iter->freq所对应的元素删除
            freq_table[iter->freq].erase(iter);
            //list中元素为空，则将该list删除
            if(freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);
                if(minfreq == freq)
                    minfreq += 1;
            }
            freq_table[freq+1].push_front(new_node);
            iter_table[key] = freq_table[freq+1].begin();   
        }
    }
private:   
    struct Value
    {   
        Value(int key_, int value_, int freq_)
         : key(key_),
           value(value_),
           freq(freq_) {}
        int key;
        int value;
        int freq;
    };
    int capacity;
    int minfreq;
    unordered_map<int, list<Value>::iterator> iter_table;
    unordered_map<int, list<Value> > freq_table;
};

int main()
{
    LFUCache_Double_Table cache(2);
    cache.put(1,1);
    cache.put(2,2);
    std::cout << cache.get(1) << "\n";
    cache.put(3,3);
    std::cout << cache.get(2) << "\n";;
    std::cout << cache.get(3) << "\n";;
    cache.put(4,4);
    std::cout << cache.get(1) << "\n";;
    std::cout << cache.get(3) << "\n";;
    std::cout << cache.get(4) << "\n";
}