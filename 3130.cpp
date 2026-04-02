#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;
    int LIMIT;

    int dfs(vector<vector<vector<int>>> &memories, int i, int j, int k)
    {
        if (i == 0)
        {
            return k == 1 && j <= LIMIT;
        }
        if (j == 0)
        {
            return k == 0 && i <= LIMIT;
        }

        int &response = memories[i][j][k];
        if (response != -1)
        {
            return response;
        }

        if (k == 0)
        {
            response = ((long long)dfs(memories, i - 1, j, 0) +
                        (long long)dfs(memories, i - 1, j, 1) +
                        (i > LIMIT ? MOD - dfs(memories, i - LIMIT - 1, j, 1) : 0)) %
                       MOD;
        }
        else
        {
            response = ((long long)dfs(memories, i, j - 1, 0) +
                        (long long)dfs(memories, i, j - 1, 1) +
                        (j > LIMIT ? MOD - dfs(memories, i, j - LIMIT - 1, 0) : 0)) %
                       MOD;
        }

        return response;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int answer = 0;
        vector<vector<vector<int>>> memories(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
        LIMIT = limit;

        answer = (dfs(memories, zero, one, 0) + dfs(memories, zero, one, 1)) % MOD;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int zero = 20;
    int one = 17;
    int limit = 3;

    int answer = solution.numberOfStableArrays(zero, one, limit);
    cout << answer << endl;

    return 0;
}
