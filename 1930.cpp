#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int answer = 0, length = s.length();

        vector<bool> used(26, false);
        for (int i = 0; i < length - 2; i++)
        {
            if (used[s[i] - 'a'])
                continue;

            for (int j = length - 1; j > i + 1; j--)
            {
                if (s[i] == s[j])
                {
                    vector<bool> met(26, false);
                    for (int k = i + 1; k < j; k++)
                        if (!met[s[k] - 'a'])
                            answer += met[s[k] - 'a'] = true;
                    break;
                }
            }

            used[s[i] - 'a'] = true;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aabca";

    int answer = solution.countPalindromicSubsequence(s);
    cout << answer << endl;

    return 0;
}
