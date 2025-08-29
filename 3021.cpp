#include <iostream>
using namespace std;

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long answer = 0;

        long long n_eve = (n - n % 2) / 2, m_eve = (m - m % 2) / 2;
        answer = n_eve * (m - m_eve) + (n - n_eve) * m_eve;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 3;
    int m = 2;

    long long answer = solution.flowerGame(n, m);
    cout << answer << endl;

    return 0;
}
