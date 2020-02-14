#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* build(vector<int>& preorder, int p_start, int p_end, vector<int> &inorder, int i_start, int i_end)
    {
        if(p_start == p_end)
            return NULL;
        //前序遍历的首元素是根节点
        int root_val = preorder[p_start];
        TreeNode* root = new TreeNode(root_val);

        int i_root; //中序遍历中根节点的位置
        //在中序遍历中找出根节点
        for(int i = i_start; i < i_end; ++i)
        {
            if(inorder[i] == root_val)
            {
                i_root = i;
                break;
            }
        }
        int left_len = i_root - i_start;
        //递归
        root->left = build(preorder, p_start + 1, p_start + left_len + 1, inorder, i_start, i_root);
        root->right = build(preorder, p_start + left_len + 1, p_end, inorder, i_root + 1, i_end);
        return root;
    }
};
