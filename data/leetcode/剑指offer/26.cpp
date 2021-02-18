#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//bfs法
class Solution2 
{
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if(A == NULL || B == NULL)
            return false;
        queue<TreeNode*> que;
        que.push(A);
        while(!que.empty())
        {
            TreeNode* tmp = que.front();
            que.pop();
            if(tmp->val == B->val)
            {
                if(judge(tmp, B))
                    return true;
            }
            if(tmp->left != NULL)
                que.push(tmp->left);
            if(tmp->right != NULL)
                que.push(tmp->right);
        }
        return false;

    }
    bool judge(TreeNode* A, TreeNode* B)
    {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({A, B});
        while(!que.empty())
        {
            auto tmp = que.front();
            que.pop();
            TreeNode* t_A = tmp.first;
            TreeNode* t_B = tmp.second;
            if(t_B == NULL)
                continue;
            if(t_A == NULL)
                return false;
            if(t_A != NULL && t_B != NULL && t_A->val == t_B->val)
            {
                que.push({t_A->left, t_B->left});
                que.push({t_A->right, t_B->right});
            }
            else 
                return false;
        }
        return true;
    }
};

class Solution 
{
public:
    bool helper(TreeNode* A, TreeNode* B) {

        if (A == NULL || B == NULL) 
        {
            return B == NULL ? true : false;
        }
        if (A->val != B->val) 
        {
            return false;
        }
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (A == NULL || B == NULL) 
        {
            return false;
        }
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

