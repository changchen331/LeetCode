#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> answer;
        int size = words.size();

        for (int i = 0, current = -1; i < size; i++)
        {
            if (current == groups[i])
                continue;

            answer.emplace_back(words[i]);
            current = groups[i];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words{"c"};
    vector<int> groups{0};

    vector<string> answer = solution.getLongestSubsequence(words, groups);
    for (auto &&ans : answer)
        cout << ans << " ";

    return 0;
}
