#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> preorder;
        stack<TreeNode*> s;
        TreeNode* p = root;
        s.push(p);
        preorder.emplace_back(p->val);
        p = p->left;
        while(!s.empty())
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
};