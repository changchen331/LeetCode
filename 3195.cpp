#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();

        int x_min = 1000, x_max = 0, y_min = 1000, y_max = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    x_min = min(x_min, i);
                    x_max = max(x_max, i);

                    y_min = min(y_min, j);
                    y_max = max(y_max, j);
                }
            }
        }

        answer = (x_max - x_min + 1) * (y_max - y_min + 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 0}, {0, 0}};

    int answer = solution.minimumArea(grid);
    cout << answer << endl;

    return 0;
}
