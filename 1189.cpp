#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int answer = INT_MAX;

        unordered_map<char, int> counts;
        for (auto &&c : text)
        {
            counts[c]++;
        }

        vector<char> balon = {'a', 'b', 'l', 'n', 'o'};
        for (auto &&c : balon)
        {
            if (answer == 0)
            {
                break;
            }

            if (c == 'l' || c == 'o')
            {
                answer = min(answer, counts[c] / 2);
            }
            else
            {
                answer = min(answer, counts[c]);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string text = "loonbalxballpoon";

    int answer = solution.maxNumberOfBalloons(text);
    cout << answer << endl;

    return 0;
}
