#include<vector>
#include<iostream>
#include<algorithm>
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> que;
        int count = 0;
        que.push({root, 0});
        vector<int> every_level;
        while(!que.empty())
        {
            auto temp = que.front();
            que.pop();
            //同一层节点
            if(temp.second == count)
            {
                every_level.emplace_back(temp.first->val);                        
            }
            //不是同一层，则将上一层的所有值放入res中，并且清空every_level用来存放新一层的值
            else 
            {
                res.emplace_back(every_level);
                every_level.clear();
                every_level.emplace_back(temp.first->val);
                ++count;
            }
            if(temp.first->left != NULL)
                que.push({temp.first->left, count+1});
            if(temp.first->right != NULL)
                que.push({temp.first->right, count + 1});
        }
        //最后一层节点
        res.push_back(every_level);
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    Solution res;
    auto a = res.levelOrder(root);
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[0].size(); ++j)
        {
            std::cout << a[i][j] << "    ";
        }
        std::cout << "\n";
    }
}