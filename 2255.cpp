#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int answer = 0;

        for (auto &&word : words)
        {
            bool flag = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != s[i])
                {
                    flag = false;
                    break;
                }
            }
            answer += flag;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words{"a", "b", "c", "ab", "bc", "abc"};
    string s = "abc";

    int answer = solution.countPrefixes(words, s);
    cout << answer << endl;

    return 0;
}
