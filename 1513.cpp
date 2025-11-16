#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    const int MOD = 1'000'000'007;
    int calculate(int x)
    {
        return (1L * x * (x + 1) / 2) % MOD;
    }

public:
    int numSub(string s)
    {
        int answer = 0, length = s.length();
        s.push_back('0');

        for (int position = 0, count = 0; position <= length; position++)
        {
            char c = s[position];
            if (c == '0')
            {
                answer = (answer + calculate(count)) % MOD;
                count = 0;
            }
            else
                count++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "0110111";

    int answer = solution.numSub(s);
    cout << answer << endl;

    return 0;
}
