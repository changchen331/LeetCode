#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int answer = 0, m = mat.size(), n = mat[0].size();

        for (int top = 0; top < m; top++)
        {
            vector<int> a(n);
            for (int bottom = top; bottom < m; bottom++)
            {
                int h = bottom - top + 1;

                int last = -1;
                for (int j = 0; j < n; j++)
                {
                    a[j] += mat[bottom][j];
                    if (a[j] != h)
                        last = j;
                    else
                        answer += j - last;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};

    int answer = solution.numSubmat(mat);
    cout << answer << endl;

    return 0;
}
