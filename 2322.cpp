#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> &nums, vector<vector<int>> &g, vector<int> &xr, vector<int> &in, vector<int> &out, int &clock, int x, int fa)
    {
        in[x] = ++clock; // 递
        xr[x] = nums[x];
        for (int y : g[x])
        {
            if (y != fa)
            {
                dfs(nums, g, xr, in, out, clock, y, x);
                xr[x] ^= xr[y];
            }
        }
        out[x] = clock; // 归
    }

public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> xr(n), in(n), out(n);
        int clock = 0;
        dfs(nums, g, xr, in, out, clock, 0, -1);

        // 判断 x 是否为 y 的祖先
        auto is_ancestor = [&](int x, int y) -> bool
        {
            return in[x] < in[y] && in[y] <= out[x];
        };

        int ans = INT_MAX;
        // 枚举：删除 x 与 x 父节点之间的边，删除 y 与 y 父节点之间的边
        for (int x = 2; x < n; x++)
        {
            for (int y = 1; y < x; y++)
            {
                int a, b, c;
                if (is_ancestor(x, y))
                    a = xr[y], b = xr[x] ^ a, c = xr[0] ^ xr[x]; // x 是 y 的祖先
                else if (is_ancestor(y, x))
                    a = xr[x], b = xr[y] ^ a, c = xr[0] ^ xr[y]; // y 是 x 的祖先
                else
                    a = xr[x], b = xr[y], c = xr[0] ^ a ^ b; // x 和 y 分别属于两棵不相交的子树

                ans = min(ans, max({a, b, c}) - min({a, b, c}));
                if (ans == 0)
                    return 0; // 不可能变小,提前返回
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 5, 5, 4, 11};
    vector<vector<int>> edges{{0, 1}, {1, 2}, {1, 3}, {3, 4}};

    int answer = solution.minimumScore(nums, edges);
    cout << answer << endl;

    return 0;
}
