#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归遍历

// 前序遍历
void preorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}
// 中序遍历
void inorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
// 后序遍历
void postorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
// type :
// 1 : pre
// 2 : mid
// 3 : post

vector<int> Traversal(TreeNode *root, int type)
{
    vector<int> res;
    if (type == 1)
        preorder(root, res);
    else if (type == 2)
        inorder(root, res);
    else if (type == 3)
        postorder(root, res);
    return res;
}
int main()
{

    return 0;
}