#include <iostream>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n)
    {
        int answer = 1;

        int current = 1;
        while (answer < n)
        {
            answer += 2 * current;
            current *= 2;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.smallestNumber(n);
    cout << answer << endl;

    return 0;
}
