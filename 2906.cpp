#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 12345;

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector answer(m, vector<int>(n, 1));

        vector prefix(m, vector<int>(n, 1));
        int product = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                product = ((prefix[i][j] = product) * (grid[i][j] % MOD)) % MOD;
            }
        }

        product = 1;
        for (int i = m - 1; i > -1; i--)
        {
            for (int j = n - 1; j > -1; j--)
            {
                answer[i][j] = (prefix[i][j] * product) % MOD;
                product = (product * (grid[i][j] % MOD)) % MOD;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};

    vector<vector<int>> answer = solution.constructProductMatrix(grid);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
