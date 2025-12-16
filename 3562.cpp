#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> g;

    vector<vector<int>> dfs(int x, vector<int> &present, vector<int> &future, int budget)
    {
        vector<vector<int>> sub_f(budget + 1, vector<int>(2, 0));

        for (auto &&y : g[x])
        {
            auto fy = dfs(y, present, future, budget);
            // 枚举子树 y 的预算为 jy
            // 当作一个体积为 jy，价值为 fy[jy][k] 的物品
            for (int j = budget; j >= 0; j--)
                for (int jy = 0; jy <= j; jy++)
                    for (int k = 0; k < 2; k++)
                        // k=0 表示 x 不买，k=1 表示 x 买
                        sub_f[j][k] = max(sub_f[j][k], sub_f[j - jy][k] + fy[jy][k]);
        }

        // 计算从子树 x 中，能得到的最大利润之和（x 父节点不买，x 父节点买）
        vector<vector<int>> f(budget + 1, vector<int>(2, 0));
        for (int j = 0; j <= budget; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                // k=0 表示 x 父节点不买，k=1 表示 x 父节点买
                int cost = present[x] / (k + 1);
                if (j >= cost)
                    // 不买 x，转移来源是 sub_f[j][0]
                    // 买 x，转移来源为 sub_f[j-cost][1]，因为对于子树来说，父节点一定买
                    f[j][k] = max(sub_f[j][0], sub_f[j - cost][1] + future[x] - cost);
                else
                    f[j][k] = sub_f[j][0]; // 只能不买 x
            }
        }
        return f;
    }

public:
    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
    {
        int answer = 0;

        g.resize(n);
        for (auto &&h : hierarchy)
            g[h[0] - 1].emplace_back(h[1] - 1);

        answer = dfs(0, present, future, budget)[budget][0];
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    vector<int> present = {1, 2};
    vector<int> future = {4, 3};
    vector<vector<int>> hierarchy = {{1, 2}};
    int budget = 3;

    int answer = solution.maxProfit(n, present, future, hierarchy, budget);
    cout << answer << endl;

    return 0;
}
