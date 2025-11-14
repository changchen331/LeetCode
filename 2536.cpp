#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> answer(n, vector<int>(n, 0));

        // 模拟
        // for (auto &&query : queries)
        // {
        //     int xl = query[0], yt = query[1], xr = query[2], yb = query[3];
        //     for (int x = xl; x <= xr; x++)
        //         for (int y = yt; y <= yb; y++)
        //             answer[x][y]++;
        // }

        // 二维拆分
        vector<vector<int>> diff(n + 2, vector<int>(n + 2, 0));
        for (auto &&query : queries)
        {
            int xl = query[0], yt = query[1], xr = query[2], yb = query[3];
            diff[xl + 1][yt + 1]++;
            diff[xl + 1][yb + 2]--;
            diff[xr + 2][yt + 1]--;
            diff[xr + 2][yb + 2]++;
        }

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                diff[x + 1][y + 1] += diff[x + 1][y] + diff[x][y + 1] - diff[x][y];
                answer[x][y] = diff[x + 1][y + 1];
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};

    vector<vector<int>> answer = solution.rangeAddQueries(n, queries);
    for (auto &&ans : answer)
    {
        for (auto &&a : ans)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
