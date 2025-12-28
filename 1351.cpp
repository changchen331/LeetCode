#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int answer = 0, m = grid.size(), n = grid[0].size();

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] >= 0)
                    break;
                answer++;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

    int answer = solution.countNegatives(grid);
    cout << answer << endl;

    return 0;
}
