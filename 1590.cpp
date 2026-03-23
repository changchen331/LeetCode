#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;

    int m, n;
    vector<vector<pair<long long, long long>>> memories;
    pair<long long, long long> dfs(vector<vector<int>> &grid, int x, int y)
    {
        long long current = grid[x][y];

        if (x == m - 1 && y == n - 1)
            return {current, current};

        auto &response = memories[x][y];
        if (response.first != LLONG_MIN)
            return response;

        long long minimum = LLONG_MAX;
        long long maximum = LLONG_MIN;
        if (x + 1 < m)
        {
            auto [mini, maxi] = dfs(grid, x + 1, y);
            long long candidate1 = mini * current;
            long long candidate2 = maxi * current;
            minimum = min(candidate1, candidate2);
            maximum = max(candidate1, candidate2);
        }
        if (y + 1 < n)
        {
            auto [mini, maxi] = dfs(grid, x, y + 1);
            long long candidate1 = mini * current;
            long long candidate2 = maxi * current;
            minimum = min(minimum, min(candidate1, candidate2));
            maximum = max(maximum, max(candidate1, candidate2));
        }

        response = {minimum, maximum};
        return response;
    }

public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int answer = 0;
        m = grid.size(), n = grid[0].size();
        memories = vector(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        long long temp = dfs(grid, 0, 0).second;
        answer = temp < 0 ? -1 : temp % MOD;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};

    int answer = solution.maxProductPath(grid);
    cout << answer << endl;

    return 0;
}
