#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {

        int answer = 0, length = text.length();

        unordered_set<char> letter;
        for (auto &&brokenLetter : brokenLetters)
            letter.insert(brokenLetter);

        for (int current = 0; current <= length; current++)
        {
            int c = current < length ? text[current] : 'E';
            if (letter.find(c) != letter.end())
            {
                while (current <= length && text[current] != ' ')
                    current++;
            }
            else if (c == ' ' || current == length)
                answer++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string text = "hello world";
    string brokenLetters = "adc";

    int answer = solution.canBeTypedWords(text, brokenLetters);
    cout << answer << endl;

    return 0;
}
