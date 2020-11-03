//二叉树的最近公共祖先

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
    void dfs(TreeNode* node)
    {
        if(node->left != NULL)
        {
            ancestor[node->left] = node;
            dfs(node->left);
        }
        if(node->right != NULL)
        {
            ancestor[node->right] = node;
            dfs(node->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
            return NULL;
        ancestor[root] = NULL;
        dfs(root);
        unordered_map<TreeNode*, bool> judge;
        while(p != NULL)
        {
            judge[p] = true;
            p = ancestor[p];
        }
        while(q != NULL)
        {
            if(judge[q])
                return q;
            q = ancestor[q];
        }
        return NULL;
    }
private:  
    unordered_map<TreeNode*, TreeNode*> ancestor;
};