#include <vector>
#include <iostream>
using namespace std;

const int MAX_ANSWERS = 10'000;
const int MAX_COUNTS = 36;

vector<int> ANSWERS(MAX_ANSWERS + 1, 0);
vector<int> COUNTS(MAX_COUNTS + 1, 0);
int init = []()
{
    int maximum = 0, count = 0;
    for (int i = 0; i < MAX_ANSWERS; i += 10)
    {
        int temp = i, sum = 0;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }

        for (int j = 0; j < 10; j++, sum++)
        {
            if (i + j == 0)
                continue;

            COUNTS[sum] += 1;
            if (COUNTS[sum] > maximum)
            {
                maximum = COUNTS[sum];
                ANSWERS[i + j] = count = 1;
            }
            else if (COUNTS[sum] == maximum)
                ANSWERS[i + j] = ++count;
            else
                ANSWERS[i + j] = count;
        }
    }
    ANSWERS[MAX_ANSWERS] = max(COUNTS[1] + 1, ANSWERS[MAX_ANSWERS - 1]);

    return 0;
}();

class Solution
{
public:
    int countLargestGroup(int n)
    {
        return ANSWERS[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;

    int answer = solution.countLargestGroup(n);
    cout << answer << endl;

    return 0;
}
