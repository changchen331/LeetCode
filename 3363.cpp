#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &fruits, vector<vector<int>> &memories, int i, int j)
    {
        int size = fruits.size();

        if (j < size - 1 - i || j >= size)
            return 0;
        if (i == 0)
            return fruits[i][j];

        int &response = memories[i][j];
        if (response != -1)
            return response;
        return response = max({dfs(fruits, memories, i - 1, j - 1), dfs(fruits, memories, i - 1, j), dfs(fruits, memories, i - 1, j + 1)}) + fruits[i][j];
    }

public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int answer = 0, size = fruits.size();
        vector<vector<int>> memories(size, vector<int>(size, -1));

        // 左上 (0,0)
        for (int i = 0; i < size; i++)
        {
            answer += fruits[i][i];
            fruits[i][i] = 0;
        }

        // 左下 (n-1,0)
        answer += dfs(fruits, memories, size - 2, size - 1);

        // 右上
        for (int i = 0; i < size; i++)
            for (int j = 0; j < i; j++)
                fruits[j][i] = fruits[i][j];
        fill(memories.begin(), memories.end(), vector<int>(size, -1));

        return answer + dfs(fruits, memories, size - 2, size - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> fruits{{1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    int answer = solution.maxCollectedFruits(fruits);
    cout << answer << endl;

    return 0;
}
