#include <vector>
#include <queue>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int len = que.size();
            vector<int> rec;
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                rec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(rec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};