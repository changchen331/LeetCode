#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> answer;
        words.push_back("EAGLE");
        int size = words.size();

        for (int front = 0, back = 1; front < size - 1;)
        {
            string f = words[front];
            sort(f.begin(), f.end());

            for (; back < size; back++)
            {
                string b = words[back];
                sort(b.begin(), b.end());

                if (f != b)
                {
                    answer.emplace_back(words[front]);
                    front = back++;
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
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};

    vector<string> answer = solution.removeAnagrams(words);
    for (auto &&ans : answer)
        cout << ans << " ";
    cout << endl;

    return 0;
}
