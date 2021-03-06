#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)   
            return NULL;
        dfs(root);
        ancestor_[root] = NULL;    
        while(p)
        {
            judge_[p] = true;
            p = ancestor_[p];
        }
        while(q)
        {
            if(judge_.count(q))
                return q;
            q = ancestor_[q];
        }
        return NULL;
    }
    void dfs(TreeNode* root)
    {
        if(root->left)
        {
            ancestor_[root->left] = root;
            dfs(root->left);
        }
        if(root->right)
        {
            ancestor_[root->right] = root;
            dfs(root->right);
        }
    }
private:   
    unordered_map<TreeNode*, TreeNode*> ancestor_;
    unordered_map<TreeNode*, bool> judge_;    
};