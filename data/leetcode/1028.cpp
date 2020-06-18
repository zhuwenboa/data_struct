#include<iostream>
#include<vector>
#include<memory>
#include<stack>

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
    TreeNode* recoverFromPreorder(string S) 
    {
        stack<TreeNode*> path;
        int pos = 0; //当前S下标位置
        while(pos < S.size())
        {
            int depth = 0; //深度
            while(S[pos] == '-')
            {
                ++depth;
                ++pos;
            }
            //将数字转换出来
            int value = 0;
            while(pos < S.size() && isdigit(S[pos]))
            {
                value = value*10 + (S[pos] - '0');
                ++pos;
            }
            TreeNode* node = new TreeNode(value);
            //深度等于栈的大小，证明在左子树上
            if(depth == path.size())
            {
                if(!path.empty())
                    path.top()->left = node;
            }
            //在右子树上
            else 
            {
                //在右子树上则需要先将要插入深度的节点的子节点全部弹出
                while(depth != path.size())
                {
                    path.pop();
                }
                path.top()->right = node;
            }
            path.push(node);
        }
        while(path.size() > 1)
            path.pop();
        return path.top();
    }
};