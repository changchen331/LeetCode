#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int &current = mat[i][j];
                if (i % 2)
                {
                    int later = mat[i][(j + k) % n];
                    if (current != later)
                        return false;
                }
                else
                {
                    int later = mat[i][(j - (k % n) + n) % n];
                    if (current != later)
                        return false;
                }
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
    int k = 4;

    bool answer = solution.areSimilar(mat, k);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
