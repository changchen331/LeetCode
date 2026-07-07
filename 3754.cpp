#include <iostream>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long answer = 0;

        string str = to_string(n);
        long long x = 0;
        long long sum = 0;
        for (auto &&c : str)
        {
            int digit = c - '0';
            if (digit)
            {
                x = x * 10 + digit;
                sum += digit;
            }
        }
        answer = x * sum;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3310612;

    long long answer = solution.sumAndMultiply(n);
    cout << answer << endl;

    return 0;
}
