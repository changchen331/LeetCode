#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long answer = 0;
        int m = matrix.size(), n = matrix[0].size();

        bool zero = false;
        int minimum = INT_MAX;
        int count = 0; // 记录负数个数
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = matrix[i][j];
                count += num < 0;

                num = abs(num);
                if (!zero && num == 0)
                    zero = true;
                minimum = min(minimum, num);
                answer += num;
            }
        }

        if (!zero && count % 2 == 1)
            answer -= 2 * minimum;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};

    long long answer = solution.maxMatrixSum(matrix);
    cout << answer << endl;

    return 0;
}
