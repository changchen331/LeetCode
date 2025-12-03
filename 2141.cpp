#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        sort(batteries.begin(), batteries.end(), greater());

        long long sum = reduce(batteries.begin(), batteries.end(), 0LL);
        for (auto &&battery : batteries)
        {
            if (battery <= sum / n)
                return sum / n;
            sum -= battery;
            n--;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    vector<int> batteries = {3, 3, 3};

    long long answer = solution.maxRunTime(n, batteries);
    cout << answer << endl;

    return 0;
}
