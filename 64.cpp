#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int m, n;
    vector<vector<int>> Grid;
    vector<vector<int>> mem;
    int dfs(int x, int y)
    {
        if (x == m - 1 && y == n - 1)
        {
            return Grid[x][y];
        }

        int &resp = mem[x][y];
        if (resp != -1)
        {
            return resp;
        }

        int righ = INT_MAX, down = INT_MAX;
        if (y + 1 < n)
        {
            righ = dfs(x, y + 1);
        }
        if (x + 1 < m)
        {
            down = dfs(x + 1, y);
        }
        resp = Grid[x][y] + min(righ, down);

        return resp;
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int answer = 0;
        m = grid.size();
        n = grid[0].size();

        Grid = grid;
        mem.resize(m, vector<int>(n, -1));

        answer = dfs(0, 0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int answer = solution.minPathSum(grid);
    cout << answer << endl;

    return 0;
}
