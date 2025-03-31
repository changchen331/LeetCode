#include <iostream>
using namespace std;

class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int answer = 0, length = s.length();

        for (auto &&character : s)
            answer += character == letter;

        return answer * 100 / length;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "eagle";
    char letter = 'e';

    int answer = solution.percentageLetter(s, letter);
    cout << answer << endl;

    return 0;
}
