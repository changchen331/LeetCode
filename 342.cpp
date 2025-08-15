#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> POWER_OF_FOUR;
int init = []
{
    for (int i = 0; i <= 15; i++)
        POWER_OF_FOUR.insert(pow(4, i));
    return 0;
}();

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        bool answer = false;

        if (POWER_OF_FOUR.find(n) != POWER_OF_FOUR.end())
            answer = true;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.isPowerOfFour(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
