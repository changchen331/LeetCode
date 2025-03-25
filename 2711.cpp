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
        vector<vector<int>> answer(size);

        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < length; y++)
            {
                int left = 0, right = 0, xx = x - 1, yy = y - 1;
                unordered_set<int> count;

                // 左
                while (xx >= 0 && yy >= 0)
                    count.insert(grid[xx--][yy--]);
                left = count.size();

                xx = x + 1, yy = y + 1;
                count.clear();

                // 右
                while (xx < size && yy < length)
                    count.insert(grid[xx++][yy++]);
                right = count.size();

                answer[x].push_back(abs(left - right));
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
