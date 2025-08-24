#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> answer;
        int m = mat.size(), n = mat[0].size();

        // 0：↗  1：↙
        vector<vector<int>> direction = {{-1, 1}, {1, -1}};
        for (int i = 0, x = 0, y = 0; i < m + n; i++)
        {
            vector<int> &c = direction[i % 2];

            while ((0 <= x && x < m) && (0 <= y && y < n))
            {
                answer.push_back(mat[x][y]);
                x += c[0];
                y += c[1];
            }
            x -= c[0];
            y -= c[1];

            // if (i % 2)
            //     (x + 1 < m) ? x++ : y++; // ↙
            // else
            //     (y + 1 < n) ? y++ : x++; // ↗
            (i % 2) ? ((x + 1 < m) ? x++ : y++) : ((y + 1 < n) ? y++ : x++);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> answer = solution.findDiagonalOrder(mat);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << (i == answer.size() - 1 ? "\n" : " ");

    return 0;
}
