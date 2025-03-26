#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int row_size = 0, col_size = 0;

    // 我的解法（超时）
    int answer = 0;
    void dfs(int x, int y, vector<vector<int>> &obstacleGrid)
    {
        if (x == row_size - 1 && y == col_size - 1 && obstacleGrid[x][y] == 0)
        {
            answer++;
            return;
        }

        // 向下
        if (x + 1 < row_size && obstacleGrid[x + 1][y] == 0)
            dfs(x + 1, y, obstacleGrid);
        // 向右
        if (y + 1 < col_size && obstacleGrid[x][y + 1] == 0)
            dfs(x, y + 1, obstacleGrid);
    }

    // 官解
    vector<vector<int>> memories;
    int DFS(int x, int y, vector<vector<int>> &obstacleGrid)
    {
        if (x < 0 || y < 0 || obstacleGrid[x][y] == 1)
            return 0;
        else if (x == 0 && y == 0)
            return 1;
        else if (memories[x][y] >= 0)
            return memories[x][y];

        memories[x][y] = DFS(x - 1, y, obstacleGrid) + DFS(x, y - 1, obstacleGrid);
        return memories[x][y];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        row_size = obstacleGrid.size();
        col_size = obstacleGrid[0].size();

        // 我的解法（超时）
        // dfs(0, 0, obstacleGrid);
        // return answer;

        // 官解
        for (int i = 0; i < row_size; i++)
            memories.push_back(vector<int>(col_size, -1));
        return DFS(row_size - 1, col_size - 1, obstacleGrid);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    int answer = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << answer << endl;

    return 0;
}
