#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
解题思路：因为是二叉搜索树，所以当两个节点都小于当前节点时那么公共父结点肯定是左子树上的节点。
        反之则是右子树上的结点。
        如果都不是则当前结点就是公共父节点。    
*/
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* ancestor = root;
        while(ancestor != NULL)
        {
            if(p->val < ancestor->val && q->val < ancestor->val)
            {
                ancestor = ancestor->left;
            }
            else if(p->val > ancestor->val && q->val > ancestor->val)
                ancestor = ancestor->right;
            else 
                break;
        }
        return ancestor;
    }
};