#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int answer = 0, m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            int one = -1;
            bool skip = false;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (one > -1)
                    {
                        skip = true;
                        break;
                    }
                    one = j;
                }
            }
            if (skip || one == -1)
                continue;

            bool add = true;
            for (int k = 0; k < m; k++)
            {
                if (k == i)
                    continue;

                if (mat[k][one] == 1)
                {
                    add = false;
                    break;
                }
            }
            answer += add;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};

    int answer = solution.numSpecial(mat);
    cout << answer << endl;

    return 0;
}
