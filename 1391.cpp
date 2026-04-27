#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<vector<int>>> streets = {
        {},
        {{0, -1}, {0, 1}},  // 站在街道 1，可以往左或者往右
        {{-1, 0}, {1, 0}},  // 站在街道 2，可以往上或者往下
        {{0, -1}, {1, 0}},  // 站在街道 3，可以往左或者往下
        {{0, 1}, {1, 0}},   // 站在街道 4，可以往右或者往下
        {{0, -1}, {-1, 0}}, // 站在街道 5，可以往左或者往上
        {{0, 1}, {-1, 0}},  // 站在街道 6，可以往右或者往上
    };

    int m, n;
    vector<vector<bool>> memories;

    bool contains(int street, int dx, int dy)
    {
        auto &ds = streets[street];
        return ds[0][0] == dx && ds[0][1] == dy ||
               ds[1][0] == dx && ds[1][1] == dy;
    }

    bool dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x == m - 1 && y == n - 1)
        {
            return true;
        }

        memories[x][y] = true;
        for (auto &&street : streets[grid[x][y]])
        {
            int dx = street[0], dy = street[1];
            int i = x + dx, j = y + dy;
            if (0 <= i && i < m && 0 <= j && j < n &&
                !memories[i][j] && contains(grid[i][j], -dx, -dy) &&
                dfs(grid, i, j))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        bool answer = false;

        m = grid.size();
        n = grid[0].size();
        memories.resize(m, vector<bool>(n, false));

        answer = dfs(grid, 0, 0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};

    bool answer = solution.hasValidPath(grid);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
