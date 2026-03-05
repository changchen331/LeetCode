#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int answer = 0, length = s.length();

        int zero = 0, one = 0;
        for (int i = 0; i < length; i++)
        {
            int z = i % 2;
            zero += (s[i] - '0' != z);

            int o = (z + 1) % 2;
            one += (s[i] - '0' != o);
        }

        answer = min(zero, one);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "1111";

    int answer = solution.minOperations(s);
    cout << answer << endl;

    return 0;
}
