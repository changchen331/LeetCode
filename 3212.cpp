#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();

        vector<vector<int>> counts(m + 1, vector<int>(n + 1, 0));
        vector<vector<bool>> has_x(m + 1, vector<bool>(n + 1, false));
        for (int j = 1; j <= n; j++)
        {
            int count = 0;
            for (int i = 1; i <= m; i++)
            {
                char &current = grid[i - 1][j - 1];

                if (current == 'X')
                {
                    counts[i][j] = counts[i][j - 1] + ++count;
                    has_x[i][j] = true;
                }
                else
                {
                    counts[i][j] = counts[i][j - 1] + (current == 'Y' ? --count : count);
                    has_x[i][j] = has_x[i - 1][j] | has_x[i][j - 1];
                }

                answer += has_x[i][j] && (counts[i][j] == 0);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<char>> grid = {{'X', 'Y', '.'}, {'Y', '.', '.'}};

    int answer = solution.numberOfSubmatrices(grid);
    cout << answer << endl;

    return 0;
}
