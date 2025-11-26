#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int MOD = 1'000'000'007;

    vector<vector<vector<int>>> memories;
    int dfs(int i, int j, int s, vector<vector<int>> &grid, int k)
    {
        if (i < 0 && j == 0)
            return s == 0 ? 1 : 0;
        if (i < 0 || j < 0)
            return 0;
        if (memories[i][j][s] != -1)
            return memories[i][j][s];

        int temp = (s + grid[i][j]) % k;
        int response1 = dfs(i - 1, j, temp, grid, k);
        int response2 = dfs(i, j - 1, temp, grid, k);
        return memories[i][j][s] = (response1 + response2) % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();

        memories = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
        answer = dfs(m - 1, n - 1, 0, grid, k);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int k = 3;

    int answer = solution.numberOfPaths(grid, k);
    cout << answer << endl;

    return 0;
}
