#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> POWER_OF_TWO;

int init = []
{
    for (int i = 0; i < 31; i++)
        POWER_OF_TWO.insert(1 << i);
    return 0;
}();

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return POWER_OF_TWO.find(abs(n)) != POWER_OF_TWO.end();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.isPowerOfTwo(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
