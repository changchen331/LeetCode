#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;

    int bit_width(int num)
    {
        if (num == 0)
            return 0;

        int response = 0;
        while (num > 0)
        {
            num >>= 1;
            response++;
        }

        return response;
    }

public:
    int concatenatedBinary(int n)
    {
        long long answer = 0;

        for (int i = 1; i <= n; i++)
        {
            int temp = bit_width(i);
            answer = (answer << temp | i) % MOD;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.concatenatedBinary(n);
    cout << answer << endl;

    return 0;
}
