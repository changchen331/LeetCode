#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();

        vector<vector<int>> sums(m, vector<int>(n + 1, 0));
        for (int j = 1; j <= n; j++)
        {
            int sum = 0;
            for (int i = 0; i < m; i++)
            {
                sum += grid[i][j - 1];
                int temp = sums[i][j - 1] + sum;
                if (temp <= k)
                {
                    sums[i][j] = temp;
                    answer++;
                }
                else
                {
                    if (i == 0)
                        return answer;

                    sums[i][j] = k + 1;
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    int k = 20;

    int answer = solution.countSubmatrices(grid, k);
    cout << answer << endl;

    return 0;
}
