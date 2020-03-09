#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>

using namespace std;

class MaxQueue {
public:
    MaxQueue() : head(NULL), tail(head), max_data(-1)
    {}
    
    int max_value() 
    {
        if(empty())
            return -1;
        return max_data;
    }
    
    void push_back(int value) 
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        { 
            tail->next = temp;
        }
        tail = temp;
    }
    
    int pop_front() 
    {
        if(head == NULL)
            return -1;
        node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        /*
        if(head == NULL)
        {
            tail = head;
        }
        */
        return value;       
    }
private:  
    bool empty()
    {
        if(head == tail)
            return true;
        return false;
    }

    struct  node
    {
        int data;
        node* next;
        node() : next(nullptr) {}
    };

    node* head;
    node* tail;    
    int max_data;
};

int main()
{
    MaxQueue q;
    std::cout << q.pop_front() << "\n";
    std::cout << q.pop_front() << "\n";
    q.push_back(94);
    //q.push_back(16);
    //q.push_back(89);
    std::cout << q.pop_front() << "\n";
    //q.push_back(22);
    std::cout << q.pop_front() << "\n";
    q.push_back(85);
    std::cout << q.pop_front() << "\n";
}