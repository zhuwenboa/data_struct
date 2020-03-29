#include<iostream>
#include<memory>
#include<string.h>

using namespace std;

class Trie_node
{
public:    
    Trie_node(char a) : data(a), isEnding(false) 
    {
        for(int i = 0; i < 26; ++i)
            node[i] = NULL;
    }

    /*
        在trie树的结构中，
    1.可以用数组指针来存储节点，这个方法是最简单的方法，但是这个方法比较浪费存储空间。
    2.可以使用有序数组(不用下标查询)来存储，将指针所指的字符进行排序，通过二分查找来进行查询，这种方法在插入和删除操作时比较麻烦耗时，但是可以节省空间。
    vector<Trie_node*>;
    3.可以使用红黑树，跳表，散列表这些数据结构来进行存储。
    */
    Trie_node* node[26];   // 只保存a-z的26个字符
    bool isEnding;
private:  
    char data;

};

class Trie_tree
{
public:   
    void insert(string str)
    {
        Trie_node* p = root;
        for(int i = 0; i < str.size(); ++i)
        {
            int index = str[i] - 'a';
            if(p->node[index] == NULL)
            {
                Trie_node* newNode = new Trie_node(str[i]);
                p->node[index] = newNode;
            }
            p = p->node[index];
        }
        p->isEnding = true; //插入一个完整的字符串
    }

    bool findString(string str)
    {
        Trie_node* p = root;
        for(int i = 0; i < str.size(); ++i)
        {
            int index = str[i] - 'a';
            if(p->node[index] == NULL)
                return false;
            p = p->node[index];
        }
        //只是其中一个字符串的前缀
        if(p->isEnding == false)
            return false;
        return true;
    }

private:  
    Trie_node* root = new Trie_node('/');
};

int main()
{
    Trie_tree res;
    res.insert("zhuwenbo");
    res.insert("zhuwen");
    res.insert("hahaha");
    std::cout << res.findString("zhuwenb") << "\n";
    std::cout << res.findString("zhuwenbo") << "\n";
}