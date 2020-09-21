#include<iostream>
#include<algorithm>
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
    //根据二叉搜索树的性质进行反向中序遍历，然后进行累加
    void order_by(TreeNode* root, int& sum)
    {
        if(root == NULL)
            return;
        order_by(root->right, sum);
        root->val += sum;
        sum = root->val;
        order_by(root->left, sum);   
    }

    TreeNode* convertBST(TreeNode* root) 
    {   
        int sum = 0;
        order_by(root, sum);
        return root;
    }
};