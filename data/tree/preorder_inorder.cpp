#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 
{
public:
    //非递归前序遍历
    vector<int> preordered(TreeNode* root)
    {
        vector<int> preorder;
        stack<TreeNode*> s;
        TreeNode* p = root;
        s.push(p);
        preorder.emplace_back(p->val);
        p = p->left;
        while(!s.empty() || p != NULL)
        {
            while(p != NULL)
            {
                s.push(p);
                preorder.emplace_back(p->val);
                p = p->left;
            }
            p = s.top()->right;
            s.pop();
        }
        return preorder;
    }
    //非递归中序遍历
    vector<int> inordered(TreeNode* root)
    {
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* p = root;
        s.push(p);
        p = p->left;
        while(!s.empty() || p != NULL)
        {
            while(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            inorder.emplace_back(p->val);
            p = p->right;
        }
        return inorder;
    }
};