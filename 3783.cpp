#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int mirrorDistance(int n)
    {
        int answer = 0;

        int num = n, reve = 0;
        while (num > 0)
        {
            reve = reve * 10 + num % 10;
            num /= 10;
        }
        answer = abs(n - reve);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.mirrorDistance(n);
    cout << answer << endl;

    return 0;
}
