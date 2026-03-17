#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int answer = 0, m = matrix.size(), n = matrix[0].size();

        // vector<vector<int>> counts1(m + 1, vector<int>(n, 0));
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         counts1[i][j] = (matrix[i - 1][j] == 0) ? 0 : counts1[i - 1][j] + 1;

        //     vector<int> temp = counts1[i];
        //     sort(temp.begin(), temp.end(), greater<>());

        //     for (int j = 0; j < n; j++)
        //         answer = max(answer, (j + 1) * temp[j]);
        // }

        vector<int> counts1(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                counts1[j] = (matrix[i][j] == 0) ? 0 : counts1[j] + 1;

            vector<int> temp = counts1;
            sort(temp.begin(), temp.end(), greater<>());

            for (int j = 0; j < n; j++)
                answer = max(answer, (j + 1) * temp[j]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 0, 1, 0, 1}};

    int answer = solution.largestSubmatrix(matrix);
    cout << answer << endl;

    return 0;
}
