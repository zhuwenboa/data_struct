#include<iostream>
#include<vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}     
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head)
{
    ListNode* temp = head;
    while(temp != NULL)
    {
        std::cout << temp->val << "    ";
        temp = temp->next;
    }
    std::cout << "\n";
}

//在链表内部进行反转操作
class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* pre = head;
        ListNode* n = head;
        ListNode* n1 = head->next;
        int count = 1;
        while(n1 != NULL)
        {
            if(count % 2 == 1)
            {
                n1 = n1->next;
                n = n->next;
            }
            else 
            {
                n->next = n1->next;
                n1->next = pre->next;
                pre->next = n1;
                pre = pre->next;
                n1 = n->next;
                //调试函数
                //print(head);
            }
            count++;
        }
        return head;
    }
};

//用链表存储偶链和奇链
class Solution2 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL)
            return head;
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        ListNode* l1_tmp = l1;
        ListNode* l2_tmp = l2;
        int count = 1;
        head = head->next;
        while(head != NULL)
        {
            head = head->next;
            if(count % 2 == 1)
            {
                l1_tmp->next = head;
                if(head != NULL)
                    l1_tmp = head;
            }
            else
            {
                l2_tmp->next = head;
                l2_tmp = head;
            }
            ++count;
        }
        l1_tmp->next = l2;
        return l1;
    }
};


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    int i = 2;
    while(i <= 5)
    {
        ListNode* p = new ListNode(i);
        temp->next = p;
        temp = p;
        ++i;
    }
    Solution2 res;
    head = res.oddEvenList(head);
    print(head);
}