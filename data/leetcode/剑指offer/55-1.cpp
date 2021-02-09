#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

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
    int bfs(TreeNode* root)
    {
        queue<TreeNode*> que;
        int depth = 0; 
        if(!root)
            return depth;
        que.push(root);
        while(!que.empty())    
        {
            int n = que.size();
            for(int i = 0; i < n; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            depth++;
        }
        return depth;   
    }

    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    int maxDepth(TreeNode* root) 
    {
        return dfs(root);
    }
};