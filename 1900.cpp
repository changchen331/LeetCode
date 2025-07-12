#include <bit>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int bit_width_math(unsigned x)
    {
        return x == 0 ? 0 : static_cast<int>(std::log2(x)) + 1;
    }

    int countr_zero(int x)
    {
        if (x == 0)
            return 32;
        int count = 0;
        while ((x & 1) == 0)
        {
            x >>= 1;
            count++;
        }
        return count;
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        if (firstPlayer + secondPlayer == n + 1)
            return {1, 1};

        if (firstPlayer + secondPlayer > n + 1)
            tie(firstPlayer, secondPlayer) = pair(n + 1 - secondPlayer, n + 1 - firstPlayer);

        auto calc_earliest_rounds = [&](int n) -> int
        {
            int res = 1;

            if (firstPlayer + secondPlayer <= (n + 1) / 2)
            {
                // 计算满足 first+second > ceil(n / 2^(k+1)) 的最小 k，推导过程见题解
                int k = bit_width_math((n - 1u) / (firstPlayer + secondPlayer - 1)) - 1;
                n = ((n - 1) >> k) + 1; // n = ceil(n / 2^k)
                res += k;

                if (secondPlayer - firstPlayer > 1)
                    return res + 1;
            }

            // 情况 1 和情况 3 合并，情况 2 合并到最后的 return
            if (secondPlayer - firstPlayer == 1 || secondPlayer > (n + 1) / 2 && secondPlayer - firstPlayer == 2)
            {
                // 先把 n 变成 ceil(n/2)，然后计算需要多少次 ceil(n/2) 的操作才能把 n 变成偶数，推导过程见题解
                // 这里把 (n+1)/2 和 n-1 合并，得到 (n+1)/2-1 = (n-1)/2
                return res + 1 + countr_zero((n - 1u) / 2);
            }

            if (secondPlayer > (n + 1) / 2 && firstPlayer % 2 == 0 && firstPlayer + secondPlayer == n)
                res++;

            return res + 1;
        };

        int earliest = calc_earliest_rounds(n);
        int latest = min(bit_width_math(n - 1u), n + 1 - secondPlayer);
        return {earliest, latest};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 11, firstPlayer = 2, secondPlayer = 4;

    vector<int> answer = solution.earliestAndLatest(n, firstPlayer, secondPlayer);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}
