#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for (int x = 1; x < m; x++)
            for (int y = 1; y < n; y++)
                grid[x][y] = grid[x - 1][y] + grid[x][y - 1];
        return grid[m - 1][n - 1];
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
