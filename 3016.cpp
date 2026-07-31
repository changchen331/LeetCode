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

        // 统计词频
        vector<int> mem(26, 0);
        for (auto &&c : word)
        {
            mem[c - 'a']++;
        }

        // 词频排序
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

        // 计算次数
        for (int i = 0; i < freq.size(); i++)
        {
            answer += (i / 8 + 1) * freq[i];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "aabbccddeeffgghhiiiiii";

    int answer = solution.minimumPushes(word);
    cout << answer << endl;

    return 0;
}
