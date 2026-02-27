#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> POWER_OF_TWO;

int init = []
{
    for (int i = 0; i < 31; i++)
        POWER_OF_TWO.emplace_back(1 << i);
    return 0;
}();

struct Comparator
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second < b.second;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(int argc, char const *argv[])
{
    // 自定义排序规则
    vector<pair<int, int>> pairs = {{1, 2}, {2, 3}, {3, 2}, {4, 2}, {5, 2}};
    sort(pairs.begin(), pairs.end(), Comparator());

    // 创建二叉树
    vector<int> root = {1, 0, 1, 0, 1, 0, 1};
    TreeNode *head = new TreeNode(root[0]);
    queue<TreeNode *> nodes;
    nodes.push(head);
    int position = 1;
    while (!nodes.empty())
    {
        TreeNode *node = nodes.front();
        nodes.pop();

        if (position < root.size())
            nodes.push(node->left = new TreeNode(root[position++]));

        if (position < root.size())
            nodes.push(node->right = new TreeNode(root[position++]));
    }

    return 0;
}
