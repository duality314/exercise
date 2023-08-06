#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> re;
        queue<Node *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int len = que.size();
            vector<int> rec;
            for (int i = 0; i < len; i++)
            {
                Node *node = que.front();
                que.pop();
                rec.push_back(node->val);
                for (Node *child : node->children)
                {
                    if (child)
                        que.push(child);
                }
            }
            re.push_back(rec);
        }
        return re;
    }
};