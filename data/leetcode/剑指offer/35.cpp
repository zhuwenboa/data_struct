#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        Node* old = head;
        Node* rehead = new Node(0);
        Node* pre = rehead;
        map<Node*, Node*> map_;
        while(old != NULL)
        {
            Node* tmp = new Node(old->val);
            map_[old] = tmp;
            pre->next = tmp;
            pre = tmp;
            old = old->next;
        }
        Node* tmp = rehead->next;
        while(head != NULL)
        {
            if(head->random == NULL)
                tmp->random = NULL;
            else 
                tmp->random = map_[head->random];
            head = head->next;
            tmp = tmp->next;
        }
        return rehead->next;
    }
};

