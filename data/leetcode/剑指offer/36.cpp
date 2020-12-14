#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Node 
{
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) 
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) 
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution 
{
public:
    Node *pre, *head;
    Node* treeToDoublyList(Node* root) 
    {
        if(root == NULL)
            return root;
        pre = NULL;
        head = NULL;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void dfs(Node* cur)
    {
        if(cur->left != NULL)
            dfs(cur->left);
        if(pre != NULL)
            pre->right = cur;
        else 
            head = cur;
        cur->left = pre;
        pre = cur;
        if(cur->right != NULL)
            dfs(cur->right);
    }
};