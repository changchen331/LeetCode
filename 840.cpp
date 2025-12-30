#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool judge(vector<vector<int>> g, int x, int y)
    {
        int &g11 = g[x - 1][y - 1], &g12 = g[x][y - 1], &g13 = g[x + 1][y - 1];
        if (g11 < 1 || g11 == 5 || 9 < g11)
            return false;
        if (g12 < 1 || g12 == 5 || 9 < g12)
            return false;
        if (g13 < 1 || g13 == 5 || 9 < g13)
            return false;

        int &g21 = g[x - 1][y], &g22 = g[x][y], &g23 = g[x + 1][y];
        if (g21 < 1 || g21 == 5 || 9 < g21)
            return false;
        if (g23 < 1 || g23 == 5 || 9 < g23)
            return false;

        int &g31 = g[x - 1][y + 1], &g32 = g[x][y + 1], &g33 = g[x + 1][y + 1];
        if (g31 < 1 || g31 == 5 || 9 < g31)
            return false;
        if (g32 < 1 || g32 == 5 || 9 < g32)
            return false;
        if (g33 < 1 || g33 == 5 || 9 < g33)
            return false;

        int a;
        a = g11 + g12 + g13; // 1 行
        if (a != 15)
            return false;
        a = g21 + g22 + g23; // 2 行
        if (a != 15)
            return false;
        a = g31 + g32 + g33; // 3 行
        if (a != 15)
            return false;

        a = g11 + g21 + g31; // 1 列
        if (a != 15)
            return false;
        a = g12 + g22 + g32; // 2 列
        if (a != 15)
            return false;
        a = g13 + g23 + g33; // 3 列
        if (a != 15)
            return false;

        a = g11 + g22 + g33; // ↘
        if (a != 15)
            return false;
        a = g13 + g22 + g31; // ↙
        if (a != 15)
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();
        if (m < 3 || n < 3)
            return 0;

        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j] == 5)
                    answer += judge(grid, i, j);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};

    int answer = solution.numMagicSquaresInside(grid);
    cout << answer << endl;

    return 0;
}
