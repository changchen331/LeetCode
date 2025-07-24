#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TrieNode
{
    unordered_map<string, TrieNode *> son;
    string name;          // 文件夹名称
    bool deleted = false; // 删除标记
};

class Solution
{
private:
    vector<vector<string>> answer;

    string gen_expr(TrieNode *node, unordered_map<string, TrieNode *> &expr_to_node)
    {
        if (node->son.empty())
            return node->name;

        vector<string> expr;
        for (auto &&entry : node->son)
            expr.push_back("(" + gen_expr(entry.second, expr_to_node) + ")");
        sort(expr.begin(), expr.end());

        string sub_tree_expr;
        for (auto &&e : expr)
            sub_tree_expr += e;

        if (expr_to_node.find(sub_tree_expr) != expr_to_node.end())
        {
            expr_to_node[sub_tree_expr]->deleted = true;
            node->deleted = true;
        }
        else
            expr_to_node[sub_tree_expr] = node;

        return node->name + sub_tree_expr;
    }

    void dfs(TrieNode *node, vector<string> &path)
    {
        if (node->deleted)
            return;

        path.push_back(node->name);
        answer.push_back(path);

        for (auto &entry : node->son)
            dfs(entry.second, path);

        path.pop_back();
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        TrieNode *root = new TrieNode();
        for (auto &path : paths)
        {
            // 把 path 插到字典树中，见 208. 实现 Trie
            TrieNode *cur = root;
            for (auto &&s : path)
            {
                if (cur->son.find(s) == cur->son.end())
                    cur->son[s] = new TrieNode();
                cur = cur->son[s];
                cur->name = s;
            }
        }

        unordered_map<string, TrieNode *> expr_to_node; // 子树括号表达式 -> 子树根节点
        for (auto &&entry : root->son)
            gen_expr(entry.second, expr_to_node);

        vector<string> path;
        // 在字典树上回溯，仅访问未被删除的节点，并将路径记录到答案中
        // 类似 257. 二叉树的所有路径
        for (auto &&entry : root->son)
            dfs(entry.second, path);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<string>> paths{{"a"}, {"c"}, {"d"}, {"a", "b"}, {"c", "b"}, {"d", "a"}};

    vector<vector<string>> answer = solution.deleteDuplicateFolder(paths);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
            cout << (j < answer[i].size() - 1 ? ", " : "");
        }
        cout << "]" << " ";
    }
    cout << endl;

    return 0;
}
