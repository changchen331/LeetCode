#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    size_t m = matrix.size();

    for (size_t x = 0; x < m / 2; x++)
    {
      for (size_t y = x; y < m - 1 - x; y++)
      {
        int cur = matrix[x][y];
        int temp = 0;
        int xx = x;
        int yy = y;
        for (int i = 0; i < 4; i++)
        {
          int yyy = m - 1 - xx;
          temp = matrix[yy][yyy];
          matrix[yy][yyy] = cur;
          cur = temp;
          xx = yy;
          yy = yyy;
        }
      }
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<vector<int>> matrix = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

  solution.rotate(matrix);

  for (size_t i = 0; i < matrix.size(); i++)
  {
    for (size_t j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j];
      if (j < matrix[i].size() - 1)
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
