#include <iostream>
#include <vector>
#include <stack>
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
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root != NULL)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != NULL)
        {
            st.pop();
            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
            st.push(node);           // 中
            st.push(NULL);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}
// 中序遍历
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root)
    {
        st.push(root);
    }
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != nullptr)
        {
            st.pop();
            if (node->right)
                st.push(node->right);
            st.push(node);
            st.push(nullptr);
            if (node->left)
                st.push(node->left);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
        return result;
    }
}
// 后序遍历
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root)
    {
        st.push(root);
    }
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != nullptr)
        {
            st.pop();
            st.push(node);
            st.push(nullptr);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
        return result;
    }
}
// type :
// 1 : pre
// 2 : mid
// 3 : post

vector<int> Traversal(TreeNode *root, int type)
{
    vector<int> res;
    if (type == 1)
        preorderTraversal(root);
    else if (type == 2)
        inorderTraversal(root);
    else if (type == 3)
        postorderTraversal(root);
    return res;
}
int main()
{

    return 0;
}