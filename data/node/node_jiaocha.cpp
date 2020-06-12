#include <iostream>
using namespace std;
class node
{
public: 
    node(int v) : val(v), next(nullptr) 
    {}
    int val;
    struct node* next;
};
int main() 
{
    //int a;
    //cin >> a;
    struct node* head = new node(1);
    struct node* p = new node(2);
    struct node* p1 = new node(3);
    struct node* head_t = new node(4);
    head->next = p;
    p->next = p1;
    head_t->next = p1;
    
    struct node* temp = head;
    int count_1 = 1;
    while(temp->next != nullptr)
    {
        ++count_1;
        temp = temp->next;
    }
    struct node* temp2 = head_t;
    int count_2 = 1;
    while(temp2->next != nullptr)
    {
        ++count_2;
        temp2 = temp2->next;
    }
    if(temp2 == temp)
        std::cout << "链表交叉\n";

    temp = head;
    temp2 = head_t;
    if(count_2 > count_1)
    {
        int step = count_2 - count_1;
        temp2 = head_t;
        while(step > 0)
        {
            temp2 = temp2->next;
            --step;
        }
    }
    else 
    {
        int step = count_1 - count_2;
        temp = head;
        while(step > 0)
        {
            temp = temp->next;
            --step;
        }
    }
    while(temp->val != temp2->val)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

}