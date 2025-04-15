#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
    const int MOD = 1'000'000'007;

private:
    long long my_pow(long long base, long long index)
    {
        long long response = 1;

        while (index)
        {
            if (index & 1)
                response = response * base % MOD;
            base = base * base % MOD;
            index >>= 1;
        }

        return response;
    }

public:
    int countGoodNumbers(long long n)
    {
        if (n == 1)
            return 5;

        int answer = 0;
        long long even_5, odd_4;
        odd_4 = n / 2;
        even_5 = odd_4 + (n & 1);

        return answer = (my_pow(4, odd_4) * my_pow(5, even_5)) % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long n = 50;

    int answer = solution.countGoodNumbers(n);
    cout << answer << endl;

    return 0;
}
