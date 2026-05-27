#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int answer = 0;

        int length = word.length();
        vector<int> low(26, -1);
        vector<int> upp(26, length);
        for (int i = 0; i < length; i++)
        {
            char c = word[i];
            if (c <= 90)
            {
                upp[c - 65] = min(upp[c - 65], i);
            }
            else
            {
                low[c - 97] = max(low[c - 97], i);
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (low[i] == -1 || upp[i] == length)
            {
                continue;
            }

            answer += (low[i] < upp[i]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "AbBCab";

    int answer = solution.numberOfSpecialChars(word);
    cout << answer << endl;

    return 0;
}
