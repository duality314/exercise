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
    bool cmp(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return 1;
        else if (left == nullptr && right != nullptr)
            return 0;
        else if (left != nullptr && right == nullptr)
            return 0;
        else if (left->val != right->val)
            return 0;
        else
            return cmp(left->left, right->right) && cmp(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return 1;
        else
        {
            return cmp(root->left, root->right);
        }
    }
};