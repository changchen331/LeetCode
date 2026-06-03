#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        int x = 0, y = n - 1;
        while ((-1 < x && x < m) && (-1 < y && y < n))
        {
            if (matrix[x][y] > target)
            {
                y -= 1;
            }
            else if (matrix[x][y] < target)
            {
                x += 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 0;

    bool answer = solution.searchMatrix(matrix, target);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
