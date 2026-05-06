#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> answer(n, vector<char>(m));

        // #: stone
        // *: obstacle
        // .: empty
        for (int i = 0; i < m; i++)
        {
            int bottom = n - 1;
            for (int j = n - 1; j > -1; j--)
            {
                char cur = boxGrid[i][j];

                if (cur == '*')
                {
                    bottom = j - 1;
                }
                else if (cur == '#')
                {
                    if (bottom > j)
                    {
                        boxGrid[i][bottom] = '#';
                        boxGrid[i][j] = '.';
                    }
                    bottom--;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                answer[j][m - i - 1] = boxGrid[i][j];
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<char>> boxGrid = {{'#', '#', '*', '.', '*', '.'},
                                    {'#', '#', '#', '*', '.', '.'},
                                    {'#', '#', '#', '.', '#', '.'}};

    vector<vector<char>> answer = solution.rotateTheBox(boxGrid);
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
