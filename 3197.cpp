#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> Grid;
    int m = 0, n = 0;

    // [start, end)，范围是 star<=x<end
    int minimumArea(int x_start, int x_end, int y_start, int y_end)
    {
        int response = 0;
        int x_min = x_end, x_max = x_start, y_min = y_end, y_max = y_start;

        bool hasOne = false;
        for (int i = x_start; i < x_end; i++)
        {
            for (int j = y_start; j < y_end; j++)
            {
                if (Grid[i][j])
                {
                    if (!hasOne)
                        hasOne = true;

                    x_min = min(x_min, i);
                    x_max = max(x_max, i);

                    y_min = min(y_min, j);
                    y_max = max(y_max, j);
                }
            }
        }

        response = hasOne ? (x_max - x_min + 1) * (y_max - y_min + 1) : 1;
        return response;
    }

    // 横两刀
    int division_1()
    {
        int response = INT_MAX;

        if (m > 1)
        {
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = i + 1; j < m - 1; j++)
                {
                    int temp = 0;
                    temp += minimumArea(0, i + 1, 0, n);     // 上
                    temp += minimumArea(i + 1, j + 1, 0, n); // 中
                    temp += minimumArea(j + 1, m, 0, n);     // 下
                    response = min(response, temp);
                }
            }
        }

        return response;
    }

    // 上竖下横
    int division_2()
    {
        int response = INT_MAX;

        if (m > 1 && n > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    int temp = 0;
                    temp += minimumArea(0, i + 1, 0, j + 1); // 上左
                    temp += minimumArea(0, i + 1, j + 1, n); // 上右
                    temp += minimumArea(i + 1, m, 0, n);     // 下
                    response = min(response, temp);
                }
            }
        }

        return response;
    }

    // 上横下竖
    int division_3()
    {
        int response = INT_MAX;

        if (m > 1 && n > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    int temp = 0;
                    temp += minimumArea(0, i + 1, 0, n);     // 上
                    temp += minimumArea(i + 1, m, 0, j + 1); // 下左
                    temp += minimumArea(i + 1, m, j + 1, n); // 下右
                    response = min(response, temp);
                }
            }
        }

        return response;
    }

    vector<vector<int>> reverse()
    {
        vector<vector<int>> response(n, vector<int>(m));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                response[j][m - 1 - i] = Grid[i][j];

        int temp = m;
        m = n;
        n = temp;
        return response;
    }

public:
    int minimumSum(vector<vector<int>> &grid)
    {
        Grid = grid;
        m = grid.size();
        n = grid[0].size();
        int answer = m * n;

        answer = min({answer, division_1(), division_2(), division_3()});
        Grid = reverse();
        answer = min({answer, division_1(), division_2(), division_3()});

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 0, 1, 0}, {0, 1, 0, 1}};

    int answer = solution.minimumSum(grid);
    cout << answer << endl;

    return 0;
}
