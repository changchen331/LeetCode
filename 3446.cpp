#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> temp(n + n - 1);
        int count = 0, x, y;

        // 上半
        for (int j = n - 1; j > 0; j--, count++)
        {
            x = 0, y = j;
            while (x < n && y < n)
                temp[count].push_back(grid[x++][y++]);
            sort(temp[count].begin(), temp[count].end());
        }

        // 下半
        for (int i = 0; i < n; i++, count++)
        {
            x = i, y = 0;
            while (x < n && y < n)
                temp[count].push_back(grid[x++][y++]);
            sort(temp[count].begin(), temp[count].end(), greater<int>());
        }

        // 覆盖
        int current = 0;
        for (int j = n - 1; j > 0; j--, current++)
            for (int e = 0; e < temp[current].size(); e++)
                grid[e][j + e] = temp[current][e];
        for (int i = 0; i < n; i++, current++)
            for (int e = 0; e < temp[current].size(); e++)
                grid[i + e][e] = temp[current][e];

        return grid;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};

    vector<vector<int>> answer = solution.sortMatrix(grid);
    for (int i = 0; i < answer.size(); i++)
        for (int j = 0; j < answer.size(); j++)
            cout << answer[i][j] << (j < answer.size() - 1 ? " " : "\n");

    return 0;
}
