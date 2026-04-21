#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    vector<vector<int>> g;
    vector<bool> vis;
    unordered_map<int, int> diff;

    void dfs(int x, vector<int> &source, vector<int> &target)
    {
        vis[x] = true;
        diff[source[x]]++;
        diff[target[x]]--;
        for (auto &&y : g[x])
        {
            if (!vis[y])
            {
                dfs(y, source, target);
            }
        }
    }

public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int answer = 0;

        int size = source.size();
        g.resize(size);
        for (auto &&allowedSwap : allowedSwaps)
        {
            int x = allowedSwap[0], y = allowedSwap[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vis.resize(size);
        for (int i = 0; i < size; i++)
        {
            if (!vis[i])
            {
                diff.clear();
                dfs(i, source, target);
                for (auto &&d : diff)
                {
                    answer += abs(d.second);
                }
            }
        }

        return answer / 2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> source = {1, 2, 3, 4};
    vector<int> target = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};

    int answer = solution.minimumHammingDistance(source, target, allowedSwaps);
    cout << answer << endl;

    return 0;
}
