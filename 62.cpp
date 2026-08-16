#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int M, N;
    vector<vector<int>> mem;
    int dfs(int x, int y)
    {
        if (x + 1 == M && y + 1 == N)
        {
            return 1;
        }

        int &resp = mem[x][y];
        if (resp != -1)
        {
            return resp;
        }

        int righ = 0, down = 0;
        if (x + 1 < M)
        {
            down = dfs(x + 1, y);
        }
        if (y + 1 < N)
        {
            righ = dfs(x, y + 1);
        }
        resp = down + righ;

        return resp;
    }

public:
    int uniquePaths(int m, int n)
    {
        // 解法一
        // vector<vector<int>> grid(m, vector<int>(n, 1));
        // for (int x = 1; x < m; x++)
        // {
        //     for (int y = 1; y < n; y++)
        //     {
        //         grid[x][y] = grid[x - 1][y] + grid[x][y - 1];
        //     }
        // }
        // return grid[m - 1][n - 1];

        // 解法二
        M = m;
        N = n;
        mem.resize(m, vector<int>(n, -1));
        int answer = dfs(0, 0);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int m = 3;
    int n = 7;

    int answer = solution.uniquePaths(m, n);
    cout << answer << endl;

    return 0;
}
