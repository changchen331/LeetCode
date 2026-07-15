#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        int answer = 1;

        int odd = 0;
        int eve = 0;
        for (int i = 1; i <= n * 2; i++)
        {
            if (i % 2)
            {
                odd += i;
            }
            else
            {
                eve += i;
            }
        }

        answer = gcd(odd, eve);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 5;

    int answer = solution.gcdOfOddEvenSums(n);
    cout << answer << endl;

    return 0;
}
