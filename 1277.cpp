#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int answer = 0, m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j])
                {
                    dp[i + 1][j + 1] = min({dp[i][j], dp[i][j + 1], dp[i + 1][j]}) + 1;
                    answer += dp[i + 1][j + 1];
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{0, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {0, 1, 1, 1}};

    int answer = solution.countSquares(matrix);
    cout << answer << endl;

    return 0;
}
