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

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        unordered_map<int, int> rightmostValueAtDepth;
        int max_depth = -1;

        stack<TreeNode*> nodeStack;
        stack<int> depthStack;
        nodeStack.push(root);
        depthStack.push(0);

        while (!nodeStack.empty()) 
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            int depth = depthStack.top();
            depthStack.pop();

            if(node != NULL) 
            {
            	// 维护二叉树的最大深度
                max_depth = max(max_depth, depth);

                // 如果不存在对应深度的节点我们才插入
                if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()) 
                {
                    rightmostValueAtDepth[depth] =  node -> val;
                }
                /*
                先将左节点入栈是因为该题想要右试图，在相同高度下unordered_map应该记录右节点的值
                所以左节点先于右节点入栈
                */
                nodeStack.push(node -> left);
                nodeStack.push(node -> right);
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
            }
        }
        vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) 
        {
            rightView.push_back(rightmostValueAtDepth[depth]);
        }

        return rightView;
    }
};





