#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> answer(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i < m - k + 1; i++)
        {
            for (int j = 0; j < n - k + 1; j++)
            {
                vector<int> temp;
                for (int x = 0; x < k; x++)
                {
                    for (int y = 0; y < k; y++)
                    {
                        temp.push_back(grid[i + x][j + y]);
                    }
                }

                sort(temp.begin(), temp.end());
                if (temp.front() == temp.back())
                {
                    answer[i][j] = 0;
                    continue;
                }

                int minimum = INT_MAX;
                for (int z = 1; z < k * k; z++)
                {
                    int diff = temp[z] - temp[z - 1];
                    if (diff == 0)
                    {
                        continue;
                    }
                    minimum = min(minimum, abs(diff));
                }
                answer[i][j] = minimum;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, -2, 3}, {2, 3, 5}};
    int k = 2;

    vector<vector<int>> answer = solution.minAbsDiff(grid, k);
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
