#include <queue>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    const int MOD = 1'000'000'007;
    long long answer = INT_MIN;
    int total = 0;

    int cul_total(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->val + cul_total(node->left) + cul_total(node->right);
    }

    int cul_subt(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int response = node->val + cul_subt(node->left) + cul_subt(node->right);
        answer = max(answer, 1LL * response * (total - response));

        return response;
    }

public:
    int maxProduct(TreeNode *root)
    {
        total = cul_total(root);
        cul_subt(root);

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> tree = {"1", "null", "2", "3", "4", "null", "null", "5", "6"};

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

        if ((i + 1) < tree.size() && tree[i + 1] != "null")
        {
            current->right = new TreeNode(stoi(tree[i + 1]));
            nodes.push(current->right);
        }
    }

    int answer = solution.maxProduct(root);
    cout << answer << endl;

    return 0;
}
