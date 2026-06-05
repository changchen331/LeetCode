#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<string> Digits;
    string N;
    vector<int> memories;

    int dfs(int i, int mask, bool is_limit, bool is_num)
    {
        if (i == N.length())
        {
            return is_num;
        }
        if (!is_limit && is_num && (memories[i] != -1))
        {
            return memories[i];
        }

        int response = 0;
        if (!is_num)
        {
            response = dfs(i + 1, mask, false, false);
        }

        char top = is_limit ? N[i] : '9';
        for (auto &&d : Digits)
        {
            if (d[0] > top)
            {
                break;
            }
            response += dfs(i + 1, mask, is_limit && (d[0] == top), true);
        }

        if (!is_limit && is_num)
        {
            memories[i] = response;
        }

        return response;
    }

public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        int answer = 0;

        Digits = digits;
        N = to_string(n);
        memories.resize(N.length(), -1);

        answer = dfs(0, 0, true, false);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> digits = {"1", "4", "9"};
    int n = 1000000000;

    int answer = solution.atMostNGivenDigitSet(digits, n);
    cout << answer << endl;

    return 0;
}
