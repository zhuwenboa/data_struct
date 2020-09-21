#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<double> ans;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        int level = 0;     //当前在树中的层数
        double count = 0; //当前层数的节点个数
        double sum = 0;   //当前层数的总数
        while(!que.empty())
        {
            auto temp = que.front();
            que.pop();
            if(temp.first == NULL)
                continue;
            if(level == temp.second)
            {
                ++count;
            }
            else 
            {
                ans.emplace_back(sum / count);
                count = 1;
                level++;
                sum = 0;
            }
            sum += temp.first->val;
            que.push({temp.first->left, temp.second+1});
            que.push({temp.first->right, temp.second+1});
        }
        ans.emplace_back(sum / count);
        return ans;
    }
};

int main()
{

}