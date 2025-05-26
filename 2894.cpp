#include <iostream>
using namespace std;

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int answer = (1 + n) * n / 2;

        for (int i = m; i <= n; i += m)
            answer -= 2 * i;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 5;
    int m = 1;

    int answer = solution.differenceOfSums(n, m);
    cout << answer << endl;

    return 0;
}
