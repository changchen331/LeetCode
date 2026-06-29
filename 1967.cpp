#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int answer = 0;

        int size = patterns.size();
        int length = word.length();
        for (int i = 0; i < size; i++)
        {
            string pattern = patterns[i];
            int len = pattern.length();
            for (int j = 0; j + len <= length; j++)
            {
                string substr = word.substr(j, len);
                if (pattern == substr)
                {
                    answer++;
                    break;
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    int answer = solution.numOfStrings(patterns, word);
    cout << answer << endl;

    return 0;
}
