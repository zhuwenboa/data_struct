#include<iostream>
#include<vector>
#include<algorithm>
//从中序遍历后续遍历构建树

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
    TreeNode* build(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end)
    {
        if(p_start > p_end)
            return NULL;
        //找到当前树的根结点
        TreeNode* root = new TreeNode(postorder[p_end]);
        int i_root;
        for(int i = i_start; i < i_end; ++i)
        {
            if(inorder[i] == postorder[p_end])
            {
                i_root = i;
                break; 
            }
        }
        //找到根节点左子树的长度
        int left_len = i_root - i_start;
        root->left = build(inorder, i_start, i_root, postorder, p_start, p_start + left_len -1);
        root->right = build(inorder, i_root+1, i_end, postorder, p_start + left_len, p_end -1);        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};