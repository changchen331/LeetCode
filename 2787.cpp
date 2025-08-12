#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        int answer = 0;
        vector<long long> f(n + 1);
        f[0] = 1;

        for (int i = 1; pow(i, x) <= n; i++)
        {
            int current = pow(i, x);
            for (int j = n; j >= current; j--)
                f[j] += f[j - current];
        }

        answer = f[n] % 1'000'000'007;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 10;
    int x = 2;

    int answer = solution.numberOfWays(n, x);
    cout << answer << endl;

    return 0;
}
