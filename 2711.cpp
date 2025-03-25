#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
    {
        int size = grid.size(), length = grid[0].size();
        vector<vector<int>> answer(size, vector<int>(length));
        unordered_set<int> count;

        // 方法一
        // int left, right, xx, yy;
        // for (int x = 0; x < size; x++)
        // {
        //     for (int y = 0; y < length; y++)
        //     {
        //         // 左
        //         count.clear();
        //         xx = x - 1, yy = y - 1;
        //         while (xx >= 0 && yy >= 0)
        //             count.insert(grid[xx--][yy--]);
        //         left = count.size();

        //         // 右
        //         count.clear();
        //         xx = x + 1, yy = y + 1;
        //         while (xx < size && yy < length)
        //             count.insert(grid[xx++][yy++]);
        //         right = count.size();

        //         answer[x][y] = abs(left - right);
        //     }
        // }

        // 方法二
        // k = length - y + x => x = k + y - length => y = length - k + x
        // 1 <= k <= length + (size - 1)
        for (int k = 1; k < (size + length); k++)
        {
            int start_y = max(length - k + 0, 0);
            int end_y = min(length - k + (size - 1), length - 1);

            // left
            count.clear();
            for (int y = start_y; y <= end_y; y++)
            {
                int x = k + y - length;
                answer[x][y] = count.size();
                count.insert(grid[x][y]);
            }

            // right
            count.clear();
            for (int y = end_y; y >= start_y; y--)
            {
                int x = k + y - length;
                answer[x][y] = abs(answer[x][y] - (int)count.size());
                count.insert(grid[x][y]);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid{{1, 2, 3}, {3, 1, 5}, {3, 2, 1}};

    vector<vector<int>> answer = solution.differenceOfDistinctValues(grid);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
