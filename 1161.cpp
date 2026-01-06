#include <cmath>
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int answer = 0;
        queue<TreeNode *> nodes;
        nodes.push(root);

        for (int maximum = INT_MIN, sum = 0, level = 0, count = 0, node_num = 1, temp = 0; !nodes.empty();)
        {
            TreeNode *current = nodes.front();
            nodes.pop();
            count++;
            if (current->left != nullptr)
            {
                nodes.push(current->left);
                temp++;
            }
            if (current->right != nullptr)
            {
                nodes.push(current->right);
                temp++;
            }

            sum += current->val;

            if (count == node_num)
            {
                if (maximum < sum)
                {
                    maximum = sum;
                    answer = level + 1;
                }
                node_num = temp;
                count = 0;
                temp = 0;
                sum = 0;
                level++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> root = {"1"};

    TreeNode *head = new TreeNode(stoi(root[0]));
    queue<TreeNode *> nodes;
    nodes.push(head);

    for (int i = 1; i < root.size(); i += 2)
    {
        TreeNode *currentNode = nodes.front();
        nodes.pop();

        if (root[i] != "null")
        {
            currentNode->left = new TreeNode(stoi(root[i]));
            nodes.push(currentNode->left);
        }

        if (i + 1 < root.size() && root[i + 1] != "null")
        {
            currentNode->right = new TreeNode(stoi(root[i + 1]));
            nodes.push(currentNode->right);
        }
    }

    int answer = solution.maxLevelSum(head);
    cout << answer << endl;

    return 0;
}
