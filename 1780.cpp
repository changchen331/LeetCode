#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<int> POWER_OF_THREE(15);
int init = []
{
    for (int i = 0; i < 15; i++)
        POWER_OF_THREE[i] = pow(3, i);
    return 0;
}();

class Solution
{
private:
    bool dfs(int n, int current, int index)
    {
        if (current == n)
            return true;
        if (current > n)
            return false;
        if (index == 15)
            return false;

        return dfs(n, current, index + 1) ||
               dfs(n, current + POWER_OF_THREE[index], index + 1);
    }

public:
    bool checkPowersOfThree(int n)
    {
        bool answer = false;

        answer = dfs(n, 0, 0);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.checkPowersOfThree(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
