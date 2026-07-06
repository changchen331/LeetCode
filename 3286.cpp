#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> Health;
    deque<pair<int, int>> locs;
    int m, n;

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>> &grid, int x, int y)
    {
        locs.push_front({x, y});
        while (!locs.empty())
        {
            int a = locs.front().first;
            int b = locs.front().second;
            locs.pop_front();

            for (auto &&dir : dirs)
            {
                int na = a + dir.first;
                int nb = b + dir.second;
                if (na < 0 || na >= m || nb < 0 || nb >= n)
                {
                    continue;
                }

                int ng = grid[na][nb];
                int nh = Health[a][b] + ng;
                int &h = Health[na][nb];

                if (nh < h)
                {
                    h = nh;
                    if (ng)
                    {
                        locs.push_back({na, nb});
                    }
                    else
                    {
                        locs.push_front({na, nb});
                    }
                }
            }
        }

        return Health[m - 1][n - 1];
    }

public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        bool answer = true;
        m = grid.size();
        n = grid[0].size();

        Health.resize(m, vector<int>(n, INT_MAX));
        Health[0][0] = grid[0][0];

        int min_health = bfs(grid, 0, 0);
        answer = health > min_health;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{0, 1, 0, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 1, 0}};
    int health = 3;

    bool answer = solution.findSafeWalk(grid, health);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
