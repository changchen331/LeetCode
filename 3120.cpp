#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int answer = 0;

        // A=65、Z=90、a=97、z=122
        int length = word.length();
        unordered_set<char> letters;
        for (int i = 0; i < length; i++)
        {
            char letter = word[i];
            if (letters.find(letter) == letters.end())
            {
                letters.insert(letter);
                answer += (letters.find(letter + 32) != letters.end());
                answer += (letters.find(letter - 32) != letters.end());
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "aaAbcBC";

    int answer = solution.numberOfSpecialChars(word);
    cout << answer << endl;

    return 0;
}
