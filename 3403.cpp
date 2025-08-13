#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;

        string answer = "";
        int length = word.length();

        char maximum = 'E';
        for (int i = 0; i < length; i++)
        {
            char current = word[i];
            if (current > maximum)
            {
                maximum = current;
                answer = word.substr(i, min(length - i, length - numFriends + 1));
            }
            else if (current == maximum)
                answer = max(answer, word.substr(i, min(length - i, length - numFriends + 1)));
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "jmf";
    int numFriends = 3;

    string answer = solution.answerString(word, numFriends);
    cout << answer << endl;

    return 0;
}
