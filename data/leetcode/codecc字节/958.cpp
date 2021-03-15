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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
/*
    struct new_node
    {
        new_node() = default;
        new_node(TreeNode* t, int i) : node(t), index(i) {}
        TreeNode* node;
        int index;
    };
*/
    bool isCompleteTree(TreeNode* root) 
    {
        if(!root)
            return true;
        queue<TreeNode*> que;
        que.push(root);
        int flag = false;
        while(!que.empty())
        {
            TreeNode* tmp = que.front();
            que.pop();
            if(tmp == NULL)
            {
                flag = true;
                continue;
            }
            if(flag)
                return false;
            que.push(tmp->left);
            que.push(tmp->right);
        }
        return true;
    }
};