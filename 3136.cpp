#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

public:
    bool isValid(string word)
    {
        bool answer = false;

        int length = word.length();
        if (length < 3)
            return false;

        bool hasVowel = false, hasConsonant = false;
        for (auto &&c : word)
        {
            if ((c < '0' || c > '9') && (c < 'A' || c > 'z'))
                return false;

            if ('A' <= c && c <= 'z')
            {
                if (!hasVowel && vowels.find(tolower(c)) != vowels.end())
                    hasVowel = true;
                else if (!hasConsonant && vowels.find(tolower(c)) == vowels.end())
                    hasConsonant = true;
            }
        }

        answer = hasVowel & hasConsonant;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "UuE6";

    bool answer = solution.isValid(word);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
