#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> buildTree(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &&edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        return g;
    }

    int dfs(int x, int fa, int d, vector<vector<int>> &g, int k)
    {
        if (d > k)
            return 0;

        int count = 1;
        for (auto &&y : g[x])
        {
            if (y != fa)
                count += dfs(y, x, d + 1, g, k);
        }

        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int max2 = 0, size1 = edges1.size() + 1, size2 = edges2.size() + 1;
        vector<int> answer(size1);

        if (k > 0)
        {
            vector<vector<int>> g = buildTree(edges2);
            for (int i = 0; i < size2; i++)
                max2 = max(max2, dfs(i, -1, 0, g, k - 1));
        }

        vector<vector<int>> g = buildTree(edges1);
        for (int i = 0; i < size1; i++)
            answer[i] = dfs(i, -1, 0, g, k) + max2;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> edges1{{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2{{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    int k = 2;

    vector<int> answer = solution.maxTargetNodes(edges1, edges2, k);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
