#include<iostream>
#include<vector>
//验证二叉搜索树
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
    bool isValidBST(TreeNode* root) 
    {
        vector<int> vec;
        midTraverse(root, vec);
        bool flag = true;
        for(int i = 1; i <= vec.size(); ++i)
        {
            if(vec[i] < vec[i-1])
            {
                flag = false;
                break;
            }
        } 
        return flag;  
    }
    
    void midTraverse(TreeNode* root, vector<int>& vec)
    {
        if(root == NULL)
            return;
        midTraverse(root->left, vec);
        vec.emplace_back(root->val);
        midTraverse(root->right, vec);
    }
};