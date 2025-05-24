#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> answer;
        int size = words.size();

        for (int i = 0; i < size; i++)
        {
            for (auto &&ch : words[i])
            {
                if (ch == x)
                {
                    answer.emplace_back(i);
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
    vector<string> words{"leet", "code"};
    char x = 'e';

    vector<int> answer = solution.findWordsContaining(words, x);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
