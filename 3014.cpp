#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int answer = 0;
        int len = word.length();

        int count = 0;
        vector<int> mem(26, 0);
        for (int i = 0; i < len; i++)
        {
            int p = word[i] - 'a';
            count += mem[p] == 0;
            mem[p]++;
        }

        // 写法一
        // for (int i = 0; i < count; i++)
        // {
        //     int mp = 0;
        //     for (int j = 1; j < 26; j++)
        //     {
        //         if (mem[j] == 0)
        //         {
        //             continue;
        //         }

        //         if (mem[mp] < mem[j])
        //         {
        //             mp = j;
        //         }
        //     }
        //     answer += (i / 8 + 1) * mem[mp];
        //     mem[mp] = 0;
        // }

        // 写法二
        vector<int> freq;
        for (auto &&m : mem)
        {
            if (m == 0)
            {
                continue;
            }
            freq.push_back(m);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        for (int i = 0; i < count; i++)
        {
            answer += (i / 8 + 1) * freq[i];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "xycdefabgggg";

    int answer = solution.minimumPushes(word);
    cout << answer << endl;

    return 0;
}
