#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int num = n;
        int sum = 0;
        int pro = 1;

        while (n > 0)
        {
            int cur = n % 10;
            sum += cur;
            pro *= cur;
            n /= 10;
        }

        return num % (sum + pro) == 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.checkDivisibility(n);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
