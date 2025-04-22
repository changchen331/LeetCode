#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;
const int MAX_N = 10'000;
const int MAX_E = 13;

vector<int> EXP[MAX_N + 1];
int C[MAX_N + MAX_E][MAX_E + 1];

int init = []()
{
    // EXP[x] 为 x 分解质因数后，每个质因数的指数
    for (int x = 2; x <= MAX_N; x++)
    {
        int t = x;
        for (int i = 2; i * i <= t; i++)
        {
            int e = 0;
            for (; t % i == 0; t /= i)
                e++;
            if (e)
                EXP[x].push_back(e);
        }
        if (t > 1)
            EXP[x].push_back(1);
    }

    // 预处理组合数
    for (int i = 0; i < MAX_N + MAX_E; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= min(i, MAX_E); j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    return 0;
}();

class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        long long answer = 0;

        for (int x = 1; x <= maxValue; x++)
        {
            long long response = 1;
            for (auto &&e : EXP[x])
                response = response * C[n + e - 1][e] % MOD;
            answer += response;
        }

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    int maxValue = 5;

    int answer = solution.idealArrays(n, maxValue);
    cout << answer << endl;

    return 0;
}
