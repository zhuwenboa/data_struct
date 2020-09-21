#include<iostream>
#include<algorithm>
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

class Solution 
{
public:
    //1、层序
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            swap(node->left, node->right);

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }

        return root;
    }

    //2、先序
    void preorder(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        swap(node->left, node->right);

        preorder(node->left);
        preorder(node->right);
    }

    TreeNode* invertTree2(TreeNode* root) {
        preorder(root);
        return root;
    }


    //3、中序
    void inorder(TreeNode* root)
    {
        /*
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left);

        swap(node->left, node->right);

        inorder(node->left);
        */
        if(root == NULL)
            return;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        //st.push(root);
        while(!st.empty() || temp != NULL)
        {
            while(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            TreeNode* left = temp->left;
            temp->left = temp->right;
            temp->right = left;
            temp = temp->left;
        }
    }

    TreeNode* invertTree3(TreeNode* root) 
    {
        inorder(root);
        return root;
    }


    //4、后序
    void postprder(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        postprder(node->left);
        postprder(node->right);
        swap(node->left, node->right);
    }

    TreeNode* invertTree4(TreeNode* root) {
        postprder(root);
        return root;
    }

};

/*
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
            return root;
        TreeNode* p = root;
        while(p != NULL)
        {
            TreeNode* temp = p->left;
            p->left = p->right;
            p->right = temp;
            p = p->left;
        }
        
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            while(temp->left != nullptr)
            {
                temp = temp->left;
                st.push(temp);
            }
            if(temp->right != nullptr)
            {
                temp = temp->right;
                st.push(temp);
            }
            else 
            {
                st.pop();
            }
        }
        
        return root;
    }
};
*/