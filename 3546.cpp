#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        bool answer = false;
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        for (auto &&gr : grid)
        {
            for (auto &&g : gr)
            {
                total += g;
            }
        }

        if (total % 2)
        {
            return false;
        }
        total /= 2;

        long long left = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                left += grid[i][j];
            }
            if (left == total)
            {
                return true;
            }
        }

        long long top = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                top += grid[i][j];
            }
            if (top == total)
            {
                return true;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 4}, {2, 3}};

    bool answer = solution.canPartitionGrid(grid);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
