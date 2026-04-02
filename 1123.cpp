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

class Solution
{
private:
    pair<int, TreeNode *> dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, nullptr};
        }

        auto [left_height, left_lca] = dfs(node->left);
        auto [right_height, right_lca] = dfs(node->right);
        if (left_height > right_height)
        {
            return {left_height + 1, left_lca}; // 左子树更高
        }

        if (left_height < right_height)
        {
            return {right_height + 1, right_lca}; // 右子树更高
        }

        return {left_height + 1, node}; // 一样高
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).second;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> tree = {"3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4"};

    TreeNode *root = new TreeNode(stoi(tree[0]));
    queue<TreeNode *> nodes;
    nodes.push(root);
    for (int i = 1; i < tree.size(); i += 2)
    {
        TreeNode *current = nodes.front();
        nodes.pop();

        if (tree[i] != "null")
        {
            current->left = new TreeNode(stoi(tree[i]));
            nodes.push(current->left);
        }
        if (i + 1 < tree.size() && tree[i + 1] != "null")
        {
            current->right = new TreeNode(stoi(tree[i + 1]));
            nodes.push(current->right);
        }
    }

    TreeNode *answer = solution.lcaDeepestLeaves(root);
    queue<TreeNode *> subnodes;
    subnodes.push(answer);

    cout << "[ " << answer->val;
    while (!subnodes.empty())
    {
        TreeNode *current = subnodes.front();
        subnodes.pop();

        if (current->left != nullptr)
        {
            cout << ", " << current->left->val;
            subnodes.push(current->left);
        }
        else
        {
            cout << ", null";
        }

        if (current->right != nullptr)
        {
            cout << ", " << current->right->val;
            subnodes.push(current->right);
        }
        else
        {
            cout << ", null";
        }
    }
    cout << " ]" << endl;

    return 0;
}
