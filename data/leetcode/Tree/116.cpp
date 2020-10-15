#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        queue<Node*> que;
        if(root == NULL)
            return root;
        que.push(root);
        while(!que.empty())
        {
            Node* pre;
            Node* last;
            int n = que.size();
            for(int i = 0; i < n; ++i)
            {
                if(i == 0)
                {
                    pre = que.front();
                    last = NULL;
                }
                else 
                {
                    last = que.front();
                    pre->next = last;
                    pre = last;
                    last = NULL; 
                }
                if(pre->left)
                    que.push(pre->left);
                if(pre->right)
                    que.push(pre->right);
                que.pop();
            }          
            pre->next = last;
        }        
        return root;       
    }
};