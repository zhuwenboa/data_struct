#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
    二叉树的镜像，其实就是将二叉树的左右节点进行交换
    我们可以用bfs层序交换，也可以前序中序后序遍历进行交换
*/

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
    TreeNode* mirrorTree(TreeNode* root) 
    {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* p = que.front();
            que.pop();
            if(p == NULL)
                continue;
            swap(p->left, p->right);
            que.push(p->left);
            que.push(p->right);
        }
        return root;
    }
};