#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;
    int LIMIT;

    int dfs(vector<vector<vector<int>>> &ms, int i, int j, int k)
    {
        if (i == 0)
            return k == 1 && j <= LIMIT;
        if (j == 0)
            return k == 0 && i <= LIMIT;

        int &response = ms[i][j][k];
        if (response != -1)
            return response;

        if (k == 0)
        {
            response = ((long long)dfs(ms, i - 1, j, 0) +
                        (long long)dfs(ms, i - 1, j, 1) +
                        (i > LIMIT ? MOD - dfs(ms, i - LIMIT - 1, j, 1) : 0)) %
                       MOD;
        }
        else
        {
            response = ((long long)dfs(ms, i, j - 1, 0) +
                        (long long)dfs(ms, i, j - 1, 1) +
                        (j > LIMIT ? MOD - dfs(ms, i, j - LIMIT - 1, 0) : 0)) %
                       MOD;
        }

        return response;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        int answer = 0;

        vector<vector<vector<int>>> ms(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
        LIMIT = limit;

        answer = (dfs(ms, zero, one, 0) + dfs(ms, zero, one, 1)) % MOD;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int zero = 1;
    int one = 1;
    int limit = 2;

    int answer = solution.numberOfStableArrays(zero, one, limit);
    cout << answer << endl;

    return 0;
}
