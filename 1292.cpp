#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int mat_sum(vector<vector<int>> &sum, int r1, int c1, int r2, int c2)
    {
        return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
    }

public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int answer = 0;
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                while (i + answer < m && j + answer < n && mat_sum(sum, i, j, i + answer, j + answer) <= threshold)
                    answer++;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> mat = {{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
    int threshold = 4;

    int answer = solution.maxSideLength(mat, threshold);
    cout << answer << endl;

    return 0;
}
