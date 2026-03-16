#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<int> answer = {0, 0, 0};
    int find_min()
    {
        int response = 0;

        for (int i = 1; i < 3; i++)
            if (answer[i] < answer[response])
                response = i;

        return response;
    }

public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int minP = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int top = grid[i][j];
                if (top != answer[0] && top != answer[1] && top != answer[2])
                {
                    if (answer[minP] < top)
                    {
                        answer[minP] = top;
                        minP = find_min();
                    }
                }

                // 递增菱形规模
                for (int k = 1;; k++)
                {
                    int left = j - k;       // 左
                    int right = j + k;      // 右
                    int middle = i + k;     // 中
                    int bottom = i + 2 * k; // 下
                    if (left < 0 || right >= n || bottom >= m)
                        break;

                    // 上半
                    top += grid[middle][left] + grid[middle][right];

                    // 下半
                    int temp = top;
                    while (left + 1 != right - 1)
                    {
                        middle++;
                        temp += grid[middle][++left] + grid[middle][--right];
                    }
                    temp += grid[bottom][j];

                    if (temp != answer[0] && temp != answer[1] && temp != answer[2])
                    {
                        if (answer[minP] < temp)
                        {
                            answer[minP] = temp;
                            minP = find_min();
                        }
                    }
                }
            }
        }

        sort(answer.begin(), answer.end(), greater<>());
        for (int i = 2; i > 0; i--)
            if (answer[i] == 0)
                answer.pop_back();

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // vector<vector<int>> grid = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<vector<int>> grid = {{7, 7, 7}};

    vector<int> answer = solution.getBiggestThree(grid);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
