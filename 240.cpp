#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        int x = m - 1, y = 0;
        while ((-1 < x && x < m) && (-1 < y && y < n))
        {
            if (matrix[x][y] < target)
            {
                y += 1;
            }
            else if (matrix[x][y] > target)
            {
                x -= 1;
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
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 50;

    bool answer = solution.searchMatrix(matrix, target);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
