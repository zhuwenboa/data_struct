#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//类似于先序遍历合并 代码太繁琐
class Solution 
{
public:
    void digui(TreeNode** root, TreeNode* p1, TreeNode* p2)
    {
        if(!p1 && !p2)
            return;
        if(!p1)
        {
            *root = p2;
            digui(&(*root)->left, NULL, p2->left);
            digui(&(*root)->right, NULL, p2->right);
        }
        else if(!p2)
        {
            *root = p1;
            digui(&(*root)->left, p1->left, NULL);
            digui(&(*root)->right, p1->right, NULL);
        }
        else 
        {
            *root = p1;
            (*root)->val += p2->val;
            digui(&(*root)->left, p1->left, p2->left);
            digui(&(*root)->right, p1->right, p2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1 && !t2)
            return NULL;
        TreeNode* root = new TreeNode(0);
        digui(&root, t1, t2);
        return root;   
    }
};


//dfs 
class Solution2
{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1)
            return t2;
        if(!t2)
            return t1;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
};