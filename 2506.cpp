#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        int answer = 0;
        int size = words.size();

        // 我的解法
        // vector<unordered_set<char>> characters(size);
        // for (int i = 0; i < size; i++)
        //     for (auto &&c : words[i])
        //         characters[i].insert(c);
        // for (int i = 0; i < size - 1; i++)
        // {
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         if (characters[i].size() != characters[j].size())
        //             continue;
        //         bool flag = true;
        //         for (auto &&c : characters[i])
        //         {
        //             if (characters[j].find(c) == characters[j].end())
        //             {
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if (flag)
        //             answer++;
        //     }
        // }
        // return answer;

        // 官解
        unordered_map<int, int> strings;
        for (auto &&word : words)
        {
            int mark = 0;
            for (auto &&w : word)
                // 若 w 为 'e', 则 mark 的第 5 位为 1（10000(二进制) = 16(十进制)）
                mark |= 1 << (w - 'a');
            answer += strings[mark]++;
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> words{"aba", "aabb", "abcd", "bac", "aabc"};

    int answer = solution.similarPairs(words);
    cout << answer << endl;

    return 0;
}
