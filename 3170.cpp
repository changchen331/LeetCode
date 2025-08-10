#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string clearStars(string s)
    {
        string answer = "";
        int length = s.length();

        // 超时
        // for (int i = 0; i < length; i++)
        // {
        //     if (s[i] == '*')
        //     {
        //         int position = 0;
        //         for (int j = 1; j < i; j++)
        //         {
        //             if (s[j] == '*')
        //                 continue;

        //             if (s[j] <= s[position])
        //                 position = j;
        //         }
        //         s[position] = '~';
        //     }
        // }
        // for (auto &&c : s)
        //     if (c != '*' && c != '~')
        //         answer.push_back(c);\

        // 官解
        vector<stack<int>> letters(26);
        for (int i = 0; i < length; i++)
        {
            char current = s[i];
            if (current != '*')
            {
                letters[current - 'a'].push(i);
                continue;
            }

            for (auto &&letter : letters)
            {
                if (letter.empty())
                    continue;

                s[letter.top()] = '*';
                letter.pop();
                break;
            }
        }
        for (auto &&c : s)
            if (c != '*')
                answer.push_back(c);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aaba*";

    string answer = solution.clearStars(s);
    cout << answer << endl;

    return 0;
}
