#include <iostream>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int answer = 0;

        answer = high - low + 1;
        if (answer % 2)
        {
            if (high % 2)
                answer++;
            else
                answer--;
        }

        answer /= 2;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int low = 3;
    int high = 7;

    int answer = solution.countOdds(low, high);
    cout << answer << endl;

    return 0;
}
