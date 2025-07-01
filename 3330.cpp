#include <iostream>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int answer = 1, length = word.length();

        int last = 0;
        for (int i = 1; i < length; i++)
        {
            answer += word[last] == word[i];
            last = i;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "abbcccc";

    int answer = solution.possibleStringCount(word);
    cout << answer << endl;

    return 0;
}
