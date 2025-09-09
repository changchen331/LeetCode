#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        const int MOD = 1'000'000'007;
        long long answer = 0;

        vector<int> memories(n + 1);
        memories[1] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (i >= n - forget + 1)
                answer += memories[i];

            for (int j = i + delay; j <= min(i + forget - 1, n); j++)
                memories[j] = (memories[j] + memories[i]) % MOD;
        }

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;
    int delay = 2;
    int forget = 4;

    int answer = solution.peopleAwareOfSecret(n, delay, forget);
    cout << answer << endl;

    return 0;
}
