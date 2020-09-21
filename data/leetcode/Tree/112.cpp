#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>
#include<queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//迭代 bfs
class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
            return false;
        queue<pair<TreeNode*, int>> que;
        que.push({root, root->val});
        while(!que.empty())
        {
            pair<TreeNode*, int> temp = que.front();  
            que.pop();
            bool flag = true;
            if(temp.first->left != NULL)
            {
                flag = false;
                que.push({temp.first->left, temp.first->left->val + temp.second});
            }
            if(temp.first->right != NULL)
            {
                flag = false;
                que.push({temp.first->right, temp.first->right->val + temp.second});
            }
            if(flag)
            {
                if(temp.second == sum)
                    return true;
            }
        }
        return false;
    }
};

//递归
class Solution2 
{
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        bool flag = false;
        if(root == NULL)
            return flag;
        dfs(root, root->val, sum, flag);
        return flag;   
    }
    void dfs(TreeNode* node, int cur_sum, int sum, bool& flag)
    {
        if(flag)
            return;
        if(node->left != NULL)
            dfs(node->left, cur_sum + node->left->val, sum, flag);
        if(node->right != NULL)
            dfs(node->right, cur_sum + node->right->val, sum, flag);
        if(node->left == NULL && node->right == NULL)
        {
            if(cur_sum == sum)
            {
                flag = true;
                return;
            }
        }
    }
};