#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        sort(answers.begin(), answers.end());

        int answer = answers[0] + 1, size = answers.size(), skip = answers[0];
        for (int i = 1; i < size; i++)
        {
            int &ans = answers[i];

            if (ans != answers[i - 1])
                skip = 0;
            if (skip > 0)
            {
                skip--;
                continue;
            }

            answer += ans + 1;
            skip = ans;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> answers{1, 0, 1, 0, 0};

    int answer = solution.numRabbits(answers);
    cout << answer << endl;

    return 0;
}
