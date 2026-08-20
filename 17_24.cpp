#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        vector<int> answer(4, -1);

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));

        for (int y = 0; y < n; y++)
        {
            int temp = 0;
            for (int x = 0; x < m; x++)
            {
                temp += matrix[x][y];
                int last = 0;
                if (y != 0)
                {
                    last += sum[x][y - 1];
                }
                sum[x][y] = last + temp;
            }
        }

        // 超时
        // int maxi = INT_MIN;
        // for (int x1 = 0; x1 < m; x1++)
        // {
        //     for (int y1 = 0; y1 < n; y1++)
        //     {
        //         for (int x2 = x1; x2 < m; x2++)
        //         {
        //             for (int y2 = y1; y2 < n; y2++)
        //             {
        //                 int a = sum[x2][y2];

        //                 int b = 0;
        //                 if (y1 != 0)
        //                 {
        //                     b = sum[x2][y1 - 1];
        //                 }

        //                 int c = 0;
        //                 if (x1 != 0)
        //                 {
        //                     c = sum[x1 - 1][y2];
        //                 }

        //                 int d = 0;
        //                 if (x1 != 0 && y1 != 0)
        //                 {
        //                     d = sum[x1 - 1][y1 - 1];
        //                 }

        //                 int temp = a - b - c + d;
        //                 if (maxi < temp)
        //                 {
        //                     maxi = max(maxi, temp);
        //                     answer = {x1, y1, x2, y2};
        //                 }
        //             }
        //         }
        //     }
        // }

        // 解法二
        int maxi = INT_MIN;
        for (int x1 = 0; x1 < m; x1++)
        {
            for (int x2 = x1; x2 < m; x2++)
            {
                vector<int> colsum(n, 0);
                int top = 0;
                if (x1 != 0)
                {
                    top = sum[x1 - 1][0];
                }
                int down = sum[x2][0];
                colsum[0] = down - top;

                int y1 = 0;
                vector<int> mem(n, INT_MIN);
                mem[0] = colsum[0];
                if (mem[0] > maxi)
                {
                    maxi = mem[0];
                    answer = {x1, y1, x2, 0};
                }
                for (int y = 1; y < n; y++)
                {
                    colsum[y] = sum[x2][y];
                    if (x1 != 0)
                    {
                        colsum[y] -= sum[x1 - 1][y];
                    }

                    int cur = colsum[y] - colsum[y - 1];
                    if (mem[y - 1] + cur > cur)
                    {
                        mem[y] = mem[y - 1] + cur;
                    }
                    else if (mem[y - 1] + cur <= cur)
                    {
                        mem[y] = cur;
                        y1 = y;
                    }

                    if (mem[y] > maxi)
                    {
                        maxi = mem[y];
                        answer = {x1, y1, x2, y};
                    }
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{9, -8, 1, 3, -2},
                                  {-3, 7, 6, -2, 4},
                                  {6, -4, -4, 8, -7}};

    vector<int> answer = solution.getMaxMatrix(matrix);
    cout << "(" << answer[0] << ", " << answer[1] << ") ";
    cout << "(" << answer[2] << ", " << answer[3] << ") ";
    cout << endl;

    return 0;
}
