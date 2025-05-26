#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int answer = 0, size = words.size();

        // 方法一
        // bool lock = true;
        // for (int i = 0; i < size; i++)
        // {
        //     if (words[i] == "EAGLE")
        //         continue;

        //     bool flag = false;
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         if (words[i][0] == words[j][1] && words[i][1] == words[j][0])
        //         {
        //             answer += 4;
        //             words[j] = "EAGLE";
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if (lock && !flag && words[i][0] == words[i][1])
        //     {
        //         answer += 2;
        //         lock = false;
        //     }
        // }

        // 方法二
        vector<vector<int>> count(26, vector<int>(26, 0));
        for (auto &&word : words)
            count[word[0] - 'a'][word[1] - 'a']++;

        int odd = 0;
        for (int i = 0; i < 26; i++)
        {
            int c = count[i][i];
            answer += c - c % 2;
            odd |= c % 2;

            for (int j = i + 1; j < 26; j++)
                answer += min(count[i][j], count[j][i]) * 2;
        }

        return (answer + odd) * 2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words{"lc", "cl", "gg"};

    int answer = solution.longestPalindrome(words);
    cout << answer << endl;

    return 0;
}
