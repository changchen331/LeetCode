#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double answer = 1;
        long long power = n;
        if (power < 0)
        {
            power = -power;
            x = 1 / x;
        }

        while (power)
        {
            if (power & 1)
                answer *= x;
            x *= x;
            power >>= 1;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    double x = 2.00000;
    int n = 10;

    double answer = solution.myPow(x, n);
    cout << answer << endl;

    return 0;
}
