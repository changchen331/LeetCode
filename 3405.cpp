#include <cmath>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;
const int MX = 100'000;

// 快速幂
long long qpow(long long x, int n)
{
    long long res = 1;

    for (; n > 0; n /= 2)
    {
        if (n % 2)
            res = res * x % MOD;
        x = x * x % MOD;
    }

    return res;
}

// 计算组合数
long long F[MX];     // F[i]=i!
long long INV_F[MX]; // INV_F[i]=i!^-1

auto init = []
{
    F[0] = 1;
    for (int i = 1; i < MX; i++)
        F[i] = F[i - 1] * i % MOD;

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--)
        INV_F[i - 1] = INV_F[i] * i % MOD;

    return 0;
}();

class Solution
{
private:
    long long comb(int n, int m)
    {
        return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k)
    {
        long long answer = 0;

        answer = comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    int m = 2;
    int k = 1;

    int answer = solution.countGoodArrays(n, m, k);
    cout << answer << endl;

    return 0;
}
