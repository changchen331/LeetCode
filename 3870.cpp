#include <iostream>
using namespace std;

class Solution
{
public:
    int countCommas(int n)
    {
        int answer = 0;

        if (n >= 1000)
        {
            answer = n - 999;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 1002;

    int answer = solution.countCommas(n);
    cout << answer << endl;

    return 0;
}
