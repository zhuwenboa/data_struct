#include<iostream>
#include<vector>
#include<algorithm>

typedef struct dictEntry
{
    void* key; //键

    //值
    union 
    {
        void* val;
        uint64_t u64;
        int64_t s64;
    };
    //指向下个哈希表节点，形成链表
    struct dictEntry* next;

}dictEntry;

typedef struct dicht
{
    dicht(unsigned long s) : size(s), sizemask(s-1)
    {
        table = new dictEntry* [s];
        for(int i = 0; i < s; ++i)
        {
            table[i] = new dictEntry;
        }
    }
    ~dicht()
    {
        for(int i = 0; i < size; ++i)
        {
            delete table[i];
        }
        delete []table;
    }
    //哈希表数组
    dictEntry** table;

    //哈希表大小
    unsigned long size;

    //哈希表大小掩码，用以计算索引值，总是等于size-1
    unsigned long sizemask;

    //哈希表已有节点数
    unsigned long used;
}dicht;


class rehash_map
{
public:  
    rehash_map(unsigned long size) 
        : hash_table(size), 
          rehash_table(0),
          pri(nullptr), 
          rehashidx(-1) {}

private:  
    dicht hash_table;
    dicht rehash_table;
    void* pri;
    int rehashidx;
};