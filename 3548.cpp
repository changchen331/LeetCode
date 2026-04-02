#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    long long total = 0LL;

    // 逆时针旋转 90°
    vector<vector<int>> rotate(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector response(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                response[n - 1 - j][i] = grid[i][j];
            }
        }

        return response;
    }

    vector<vector<int>> inversion(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector response(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                response[i][j] = grid[i][n - j - 1];
            }
        }

        return response;
    }

    bool check(vector<vector<int>> grid)
    {
        int m = grid.size(), n = grid[0].size();
        unordered_set<long long> can_delete = {0};

        long long count = 0LL;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                int current = grid[i][j];
                count += current;
                // 第一列
                if (j > 0 || i == 0 || i == m - 1)
                {
                    can_delete.insert(current);
                }
            }

            // 只有一行
            if (m == 1)
            {
                if (count * 2 == total || (count * 2 - total) == grid[0][0] || (count * 2 - total) == grid[0][j])
                {
                    return true;
                }
                continue;
            }

            // 判断是否能通过删除一个元素来达到平衡
            if (can_delete.find(count * 2 - total) != can_delete.end())
            {
                return true;
            }

            // 列数 > 1，现在能删除第一列的任意元素
            if (j == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    can_delete.insert(grid[i][0]);
                }
            }
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (auto &&row : grid)
        {
            for (auto &&element : row)
            {
                total += element;
            }
        }

        if (check(grid) || check(inversion(grid)))
        {
            return true;
        }
        grid = rotate(grid);
        if (check(grid) || check(inversion(grid)))
        {
            return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{100000}, {100000}, {100000}, {100000}, {1}};

    bool answer = solution.canPartitionGrid(grid);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
