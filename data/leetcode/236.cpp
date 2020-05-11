#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//用哈希表存储每个节点的父节点 
class Solution 
{
public:
    unordered_map<int, TreeNode*> ancestor;
    unordered_map<int, bool> judge;   

    void dfs(TreeNode* root)
    {
        if(root->left != NULL)
        {
            ancestor[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right != NULL)
        {
            ancestor[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        ancestor[root->val] = nullptr;
        dfs(root);
        while(p != NULL)
        {
            judge[p->val] = true;
            p = ancestor[p->val];
        }
        while(q != NULL)
        {
            if(judge[q->val])
                return q;
            q = ancestor[q->val];
        }        
        return nullptr;
    }
};