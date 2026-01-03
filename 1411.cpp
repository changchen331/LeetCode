#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;

public:
    int numOfWays(int n)
    {
        // 121 → 212 213 232 312 313 (3*121 + 2*123)
        // 123 → 212 231 232 312 (2*121 + 2*123)
        int answer = 0L;

        long long pre121 = 6, pre123 = 6;
        for (int i = 1; i < n; i++)
        {
            long long temp121 = (pre121 * 3 + pre123 * 2) % MOD;
            long long temp123 = (pre121 * 2 + pre123 * 2) % MOD;
            pre121 = temp121;
            pre123 = temp123;
        }

        answer = (pre121 + pre123) % MOD;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 5000;

    int answer = solution.numOfWays(n);
    cout << answer << endl;

    return 0;
}
