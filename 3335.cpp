#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1'000'000'007;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        int answer = 0, size = s.length();

        vector<int> count(26, 0);
        for (auto &&c : s)
            count[c - 'a']++;

        for (int round = 0; round < t; round++)
        {
            vector<int> next(26, 0);
            next[0] = count[25];
            next[1] = (count[25] + count[0]) % MOD;

            for (int i = 2; i < 26; i++)
                next[i] = count[i - 1];
            count = move(next);
        }

        for (int i = 0; i < 26; i++)
            answer = (answer + count[i]) % MOD;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abcyy";
    int t = 2;

    int answer = solution.lengthAfterTransformations(s, t);
    cout << answer << endl;

    return 0;
}
