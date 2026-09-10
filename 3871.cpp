#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long countCommas(long long n)
    {
        long long answer = 0;

        string str = to_string(n);
        int len = str.length();

        for (int i = 3; i < len; i += 3)
        {
            long long cur = pow(10, i);
            if (cur <= n)
            {
                answer += n - cur + 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long n = 1003;

    long long answer = solution.countCommas(n);
    cout << answer << endl;

    return 0;
}
