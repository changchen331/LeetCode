#include <vector>
#include <cstdint>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;
const int MX = 31;

long long F[MX];     // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1

long long pow(long long x, int n)
{
    long long res = 1;
    for (; n; n /= 2)
    {
        if (n % 2)
            res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

auto init = []
{
    F[0] = 1;
    for (int i = 1; i < MX; i++)
        F[i] = F[i - 1] * i % MOD;

    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--)
        INV_F[i - 1] = INV_F[i] * i % MOD;

    return 0;
}();

class Solution
{
private:
    int popcount(unsigned int n)
    {
        int count = 0;
        while (n)
        {
            n &= n - 1; // 清除最低位的1
            count++;
        }
        return count;
    }

public:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        int n = nums.size();
        vector pow_v(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
        {
            pow_v[i][0] = 1;
            for (int j = 1; j <= m; j++)
                pow_v[i][j] = 1LL * pow_v[i][j - 1] * nums[i] % MOD;
        }

        vector f(n + 1, vector(m + 1, vector(m / 2 + 1, vector<int>(k + 1))));
        for (uint32_t x = 0; x <= m / 2; x++)
        {
            int c1 = popcount(x);
            if (c1 <= k)
            {
                f[n][0][x][c1] = 1;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int left_m = 0; left_m <= m; left_m++)
            {
                for (int x = 0; x <= m / 2; x++)
                {
                    for (int left_k = 0; left_k <= k; left_k++)
                    {
                        long long res = 0;
                        for (int j = 0; j <= min(left_m, m - x); j++)
                        {
                            int bit = (x + j) & 1;
                            if (bit <= left_k)
                            {
                                int r = f[i + 1][left_m - j][(x + j) >> 1][left_k - bit];
                                res = (res + 1LL * r * pow_v[i][j] % MOD * INV_F[j]) % MOD;
                            }
                        }
                        f[i][left_m][x][left_k] = res;
                    }
                }
            }
        }
        return 1LL * f[0][m][0][k] * F[m] % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int m = 5;
    int k = 5;
    vector<int> nums = {1, 10, 100, 10000, 1000000};

    int answer = solution.magicalSum(m, k, nums);
    cout << answer << endl;

    return 0;
}
