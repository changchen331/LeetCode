#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int answer = 0, length = s.length();

        long long current = 0;
        for (int i = length - 1, digit = 0; i >= 0; i--)
        {
            if (current <= k && digit <= 29 && s[i] == '1')
            {
                current += pow(2, digit);
                if (current <= k)
                {
                    answer += 1;
                    digit += 1;
                }
            }
            else if (s[i] == '0')
            {
                answer += 1;
                digit += 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "00101001";
    int k = 1;

    int answer = solution.longestSubsequence(s, k);
    cout << answer << endl;

    return 0;
}
