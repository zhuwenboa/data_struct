#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
** 这个是错误的方法，我开始觉得最长路径必须经过根节点，所以只需计算左右子树的高度相加-1就得到答案，
** 但是最长路径有可能不经过根节点而是内部的一段路径。
** 所以我们要递归寻找左右子树高度和最大的值就是经过路径最长的
*/
//下面类为错误方法
class Solution_default {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        TreeNode *left = root->left;
        root->left = NULL;
        return longroad(root) + longroad(left) -1;
    }
    int longroad(TreeNode *node)
    {
        if(node != NULL)
        {
            int leftheight = longroad(node->left);
            int rightheight = longroad(node->right);
            return max(leftheight, rightheight) +1;
        }
        return 0;
    }
};

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
            longroad(root);
        return ans;
    }
    int longroad(TreeNode *node)
    {
        if(node != NULL)
        {
            int leftheight = longroad(node->left);
            int rightheight = longroad(node->right);
            ans = max(ans, leftheight + rightheight);
            return max(leftheight, rightheight) +1;
        }
        return 0;
    }
};