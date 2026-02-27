#include <iostream>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int answer = 0;

        while ((n & 1) == 0)
            n >>= 1;

        int count = 0;
        while (n > 0)
        {
            n >>= 1;
            count++;

            if (n & 1)
            {
                answer = max(answer, count);
                count = 0;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    int answer = solution.binaryGap(n);
    cout << answer << endl;

    return 0;
}
