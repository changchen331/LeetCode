#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int cc = 0; // 编号
    void dfs(vector<vector<int>> &g, vector<int> &belong, int x)
    {
        belong[x] = cc;
        for (auto &&y : g[x])
            if (belong[y] < 0)
                dfs(g, belong, y);
    }

public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<int> answer;
        int size_c = connections.size(), size_q = queries.size();

        vector<vector<int>> g(c + 1);
        for (auto &&connection : connections)
        {
            int x = connection[0], y = connection[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> belong(c + 1, -1);
        for (int i = 1; i <= c; i++)
        {
            if (belong[i] < 0)
            {
                dfs(g, belong, i);
                cc++;
            }
        }

        vector<int> offline_time(c + 1, INT_MAX);
        for (int i = size_q - 1; i > -1; i--)
        {
            vector<int> &q = queries[i];
            if (q[0] == 2)
                offline_time[q[1]] = i; // 记录最早离线时间
        }

        // 维护每个连通块的在线电站的最小编号
        vector<int> mn(cc, INT_MAX);
        for (int i = 1; i <= c; i++)
        {
            if (offline_time[i] == INT_MAX)
            {
                int j = belong[i]; // 最终仍然在线
                mn[j] = min(mn[j], i);
            }
        }

        for (int i = size_q - 1; i >= 0; i--)
        {
            vector<int> &query = queries[i];
            int x = query[1];
            int j = belong[x];

            if (query[0] == 2)
            {
                if (offline_time[x] == i)
                    mn[j] = min(mn[j], x);
            }
            else if (i < offline_time[x])
                answer.push_back(x);
            else if (mn[j] != INT_MAX)
                answer.push_back(mn[j]);
            else
                answer.push_back(-1);
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int c = 5;
    vector<vector<int>> connections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<vector<int>> queries = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};

    vector<int> answer = solution.processQueries(c, connections, queries);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
