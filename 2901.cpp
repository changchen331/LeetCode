#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(string &a, string &b)
    {
        int length = a.length();
        if (length != b.length())
            return false;

        bool response = false;
        for (int i = 0; i < length; i++)
        {
            if (a[i] != b[i])
            {
                if (response)
                    return false;
                response = true;
            }
        }

        return response;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> answer;
        int size = words.size();

        vector<int> f(size), form(size);
        int max_i = size - 1;
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (f[j] > f[i] && groups[j] != groups[i] && check(words[j], words[i]))
                {
                    f[i] = f[j];
                    form[i] = j;
                }
            }

            f[i]++;
            if (f[i] > f[max_i])
                max_i = i;
        }

        int i = max_i, m = f[i];
        for (int k = 0; k < m; k++)
        {
            answer.emplace_back(words[i]);
            i = form[i];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words{"bab", "dab", "cab"};
    vector<int> groups{1, 2, 2};

    vector<string> answer = solution.getWordsInLongestSubsequence(words, groups);
    for (auto &&ans : answer)
        cout << ans << " ";

    return 0;
}
