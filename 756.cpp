#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_map<string, vector<char>> blocks;

    bool build_layer(string current)
    {
        if (current.length() == 1)
            return true;

        vector<string> next_layer; // 储存下一层可能的组合
        bool valid = false;

        // 遍历当层所有相邻对块
        for (int i = 0; i < current.length() - 1; i++)
        {
            string key = current.substr(i, 2);
            if (blocks.find(key) == blocks.end())
                return false; // 没有匹配的块组合

            // 收集所有可能的下一层字符
            vector<char> &candidates = blocks[key];
            if (next_layer.empty())
                for (auto &&candidate : candidates)
                    next_layer.emplace_back(string(1, candidate));
            else
            {
                vector<string> temp;
                for (auto &&nl : next_layer)
                    for (auto &&c : candidates)
                        temp.push_back(nl + c);
                next_layer = temp;
            }
        }

        // 递归尝试所有可能的下一层组合
        for (auto &&nl : next_layer)
            if (build_layer(nl))
                return true;

        return false;
    }

    string groups[6][6]{}; // 三角形底部两个字母 -> [三角形顶部字母]
    vector<string> pyramid;

    bool dfs(int i, int j)
    {
        if (i < 0)
            return true; // 所有格子都已填完
        if (j == i + 1)
            return dfs(i - 1, 0); // 开始填 i-1 行

        // 枚举 (i, j) 填什么字母，这取决于 (i+1, j) 和 (i+1, j+1) 填的字母
        for (char top : groups[pyramid[i + 1][j] - 'A'][pyramid[i + 1][j + 1] - 'A'])
        {
            pyramid[i][j] = top;
            if (dfs(i, j + 1))
                return true;
        }
        return false;
    };

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        bool answer = true;
        int m = allowed.size(), n = bottom.length();

        // 超时
        // for (auto &&a : allowed)
        //     blocks[a.substr(0, 2)].emplace_back(a[2]);
        // answer = build_layer(bottom);

        for (auto &s : allowed)
            groups[s[0] - 'A'][s[1] - 'A'] += s[2];

        pyramid.resize(n);
        for (int i = 0; i < n - 1; i++)
            pyramid[i].resize(i + 1);
        pyramid[n - 1] = move(bottom);

        // 从倒数第二行开始填
        answer = dfs(n - 2, 0);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string bottom = "BCD";
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};

    bool answer = solution.pyramidTransition(bottom, allowed);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
