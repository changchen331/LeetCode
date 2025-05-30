#include <array>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    pair<vector<vector<int>>, array<int, 2>> count(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &&edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        array<int, 2> cnt{0, 0};
        dfs(g, cnt, 0, -1, 0);
        return pair(g, cnt);
    }

    void dfs(vector<vector<int>> &g, array<int, 2> &cnt, int x, int fa, int d)
    {
        cnt[d]++;
        for (auto &&y : g[x])
            if (y != fa)
                dfs(g, cnt, y, x, d ^ 1);
    }

    void dfs2(vector<int> &answer, array<int, 2> &cnt, vector<vector<int>> &g, int x, int fa, int d)
    {
        answer[x] += cnt[d];
        for (auto &&y : g[x])
            if (y != fa)
                dfs2(answer, cnt, g, y, x, d ^ 1);
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        auto [_, cnt2] = count(edges2);
        int max2 = max(cnt2[0], cnt2[1]);

        auto [g, cnt1] = count(edges1);
        vector<int> answer(g.size(), max2);

        dfs2(answer, cnt1, g, 0, -1, 0);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> edges1{{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2{{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};

    vector<int> answer = solution.maxTargetNodes(edges1, edges2);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
