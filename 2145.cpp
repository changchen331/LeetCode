#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int answer = 0, size = differences.size();

        int minimum = differences[0], maximum = differences[0];
        long long temp = 0, count = 0;
        for (auto &&difference : differences)
        {
            temp += difference;
            minimum = min(0LL + minimum, temp);
            maximum = max(0LL + maximum, temp);
        }
        count = 1LL + upper - lower - max(0, maximum) + min(0, minimum);

        return answer = max(count, 0LL);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> differences{1, -3, 4};
    int lower = 1;
    int upper = 6;

    int answer = solution.numberOfArrays(differences, lower, upper);
    cout << answer << endl;

    return 0;
}
