#include <queue>
#include <vector>
#include <iostream>
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

/**
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
class Solution
{
private:
    int answer;

    pair<int, int> dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }

        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int size = left.second + right.second + 1;
        answer += (node->val == sum / size);

        return {sum, size};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        answer = 0;

        dfs(root);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> values = {"4", "8", "5", "0", "1", "null", "6"};

    queue<TreeNode *> nodes;
    TreeNode *head = new TreeNode(stoi(values[0]));
    nodes.push(head);
    for (int i = 1; i < values.size(); i += 2)
    {
        TreeNode *cur = nodes.front();
        nodes.pop();

        string left = values[i];
        if (left != "null")
        {
            int v = stoi(left);
            cur->left = new TreeNode(v);
            nodes.push(cur->left);
        }

        string right = values[i + 1];
        if (right != "null")
        {
            int v = stoi(right);
            cur->right = new TreeNode(v);
            nodes.push(cur->right);
        }
    }

    int answer = solution.averageOfSubtree(head);
    cout << answer << endl;

    return 0;
}
