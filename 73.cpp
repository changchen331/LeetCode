#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    // 方法一（未达题目要求）
    // unordered_set<int> lines;
    // unordered_set<int> rows;
    // for (size_t i = 0; i < m; i++)
    // {
    //   for (size_t j = 0; j < n; j++)
    //   {
    //     int c = matrix[i][j];
    //     if (c == 0)
    //     {
    //       lines.insert(i);
    //       rows.insert(j);
    //     }
    //   }
    // }

    // for (auto &&l : lines)
    // {
    //   matrix[l] = vector<int>(n, 0);
    // }
    // for (auto &&r : rows)
    // {
    //   for (size_t i = 0; i < m; i++)
    //   {
    //     int &c = matrix[i][r];
    //     if (c == 0)
    //     {
    //       continue;
    //     }
    //     c = 0;
    //   }
    // }

    // 方法二
    bool line0 = false;
    bool row0 = false;
    for (size_t i = 0; i < m; i++)
    {
      for (size_t j = 0; j < n; j++)
      {
        int c = matrix[i][j];
        if (c == 0)
        {
          if (i == 0)
          {
            line0 = true;
          }
          else
          {
            matrix[i][0] = 0;
          }

          if (j == 0)
          {
            row0 = true;
          }
          else
          {
            matrix[0][j] = 0;
          }
        }
      }
    }

    for (size_t i = m - 1; i > 0; i--)
    {
      int c = matrix[i][0];
      if (c == 0)
      {
        matrix[i] = vector<int>(n, 0);
      }
    }
    for (size_t j = n - 1; j > 0; j--)
    {
      int c = matrix[0][j];
      if (c == 0)
      {
        for (size_t i = 1; i < m; i++)
        {
          int &t = matrix[i][j];
          if (t == 0)
          {
            continue;
          }
          t = 0;
        }
      }
    }
    if (line0)
    {
      matrix[0] = vector<int>(n, 0);
    }
    if (row0)
    {
      for (size_t i = 0; i < m; i++)
      {
        int &c = matrix[i][0];
        if (c == 0)
        {
          continue;
        }
        c = 0;
      }
    }
  }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  solution.setZeroes(matrix);
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
