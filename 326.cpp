#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> POWER_OF_THREE;

int init = []
{
    for (int i = 0; i < 20; i++)
        POWER_OF_THREE.insert(pow(3, i));
    return 0;
}();

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        bool answer = false;

        if (POWER_OF_THREE.find(n) != POWER_OF_THREE.end())
            answer = true;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.isPowerOfThree(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
