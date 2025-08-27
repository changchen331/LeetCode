#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> DIRS = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;

    int dfs(vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &mem, int i, int j, int k, bool can_turn, int target)
    {
        i += DIRS[k][0];
        j += DIRS[k][1];
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target)
            return 0;

        int &response = mem[i][j][k][can_turn];
        if (response)
            return response;

        response = dfs(grid, mem, i, j, k, can_turn, 2 - target) + 1;
        if (can_turn)
        {
            vector<int> maxs = {m - i, j + 1, i + 1, n - j};
            k = (k + 1) % 4;
            if (min(maxs[k], maxs[(k + 3) % 4]) > response)
                response = max(response, dfs(grid, mem, i, j, k, false, 2 - target) + 1);
        }
        return response;
    }

public:
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int answer = 0;
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<int>>>> mem(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2))));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    vector<int> maxs = {m - i, j + 1, i + 1, n - j};
                    for (int k = 0; k < 4; k++)
                        if (maxs[k] > answer)
                            answer = max(answer, dfs(grid, mem, i, j, k, true, 2) + 1);
                }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{2, 2, 1, 2, 2},
                                {2, 0, 2, 2, 0},
                                {2, 0, 1, 1, 0},
                                {1, 0, 2, 2, 2},
                                {2, 0, 0, 2, 2}};

    int answer = solution.lenOfVDiagonal(grid);
    cout << answer << endl;

    return 0;
}
