#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        long long answer = 1;
        const int MOD = 1'000'000'007;
        int length = word.length();

        // 分组
        vector<int> counts;
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            count++;
            if (i == length - 1 || word[i] != word[i + 1])
            {
                if (count > 1)
                {
                    if (k > 0)
                        counts.push_back(count - 1);
                    answer = (answer * count) % MOD;
                }
                k--;
                count = 0;
            }
        }
        if (k <= 0)
            return answer % MOD;

        // DFS
        vector<int> memories(k, 1);
        for (auto &&c : counts)
        {
            for (int i = 1; i < k; i++)
                memories[i] = (memories[i] + memories[i - 1]) % MOD;
            for (int i = k - 1; i > c; i--)
                memories[i] = (memories[i] - memories[i - c - 1]) % MOD;
        }

        return (answer - memories[k - 1] + MOD) % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string word = "aabbccdd";
    int k = 7;

    int answer = solution.possibleStringCount(word, k);
    cout << answer << endl;

    return 0;
}
