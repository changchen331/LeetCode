#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int x_max, int y_max, int x, int y)
    {
        int current = grid[x][y];
        //  1 = \ && -1 = /
        if (current == 1 && y == y_max)
            return -1;
        if (current == -1 && y == 0)
            return -1;
        if (current != grid[x][y + current])
            return -1;

        if (x == x_max)
            return y + current;
        return dfs(grid, x_max, y_max, x + 1, y + current);
    }

public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> answer;
        int x = 0, y = 0;
        int x_max = grid.size() - 1, y_max = grid[0].size() - 1;
        for (; y <= y_max; y++)
            answer.push_back(dfs(grid, x_max, y_max, x, y));

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid{{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};

    vector<int> answer = solution.findBall(grid);
    for (auto &&a : answer)
        cout << a << "\t";
    cout << endl;

    return 0;
}
