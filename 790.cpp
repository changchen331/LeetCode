#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;

        vector<long long> memories(n + 1);

        memories[0] = memories[1] = 1;
        memories[2] = 2;
        for (int i = 3; i <= n; i++)
            memories[i] = (2 * memories[i - 1] + memories[i - 3]) % MOD;

        return memories[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;

    int answer = solution.numTilings(n);
    cout << answer << endl;

    return 0;
}
