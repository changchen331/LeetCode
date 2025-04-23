#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/* *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 树的初始化
TreeNode *init(vector<int> values)
{
    TreeNode root = TreeNode(values[0]);
    int size = values.size();

    queue<TreeNode *> nodes;
    nodes.push(&root);
    for (int i = 1; i < size; i += 2)
    {
        TreeNode *node = nodes.front();
        nodes.pop();

        if (values[i] >= 0)
            nodes.push(node->left = new TreeNode(values[i]));
        if (i + 1 < size && values[i + 1] >= 0)
            nodes.push(node->right = new TreeNode(values[i + 1]));
    }

    return &root;
}

// 展示树结构

class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> values{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode *root = init(values);

    TreeNode *answer = solution.lcaDeepestLeaves(root);

    return 0;
}
