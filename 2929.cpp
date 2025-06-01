#include <iostream>
using namespace std;

class Solution
{
private:
    long long c2(long long n)
    {
        return n > 1 ? n * (n - 1) / 2 : 0;
    }

public:
    long long distributeCandies(int n, int limit)
    {
        long long answer = 0;

        answer = c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 5;
    int limit = 2;

    long long answer = solution.distributeCandies(n, limit);
    cout << answer << endl;

    return 0;
}
