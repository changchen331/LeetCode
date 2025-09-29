#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> points;
    int dfs(vector<vector<int>> &memories, int i, int j)
    {
        if (i + 1 == j)
            return 0;

        int &response = memories[i][j];
        if (response != -1)
            return response;

        response = INT_MAX;
        for (int k = i + 1; k < j; k++)
            response = min(response, dfs(memories, i, k) + dfs(memories, k, j) + points[i] * points[j] * points[k]);

        return response;
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int answer = 0, size = values.size();
        points = values;

        vector<vector<int>> memories(size, vector<int>(size, -1));
        answer = dfs(memories, 0, size - 1);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> values = {1, 3, 1, 4, 1, 5};

    int answer = solution.minScoreTriangulation(values);
    cout << answer << endl;

    return 0;
}
