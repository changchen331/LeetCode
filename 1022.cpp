#include <queue>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

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
    int sumRootToLeaf(TreeNode *root)
    {
        int answer = 0;

        stack<pair<int, TreeNode *>> nodes;
        nodes.push({0, root});
        while (!nodes.empty())
        {
            auto [num, node] = nodes.top();
            nodes.pop();

            num = (num << 1) + node->val;
            if (node->left == nullptr && node->right == nullptr)
                answer += num;
            else
            {
                if (node->right != nullptr)
                    nodes.push({num, node->right});
                if (node->left != nullptr)
                    nodes.push({num, node->left});
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> root = {1, 1};

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

    int answer = solution.sumRootToLeaf(head);
    cout << answer << endl;

    return 0;
}
