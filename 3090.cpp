#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int answer = 0;
        int len = s.length();

        vector<int> counts(26, 0);
        int l = 0, r = 0;
        for (; r < len; r++)
        {
            int cur = s[r] - 'a';
            counts[cur]++;

            if (counts[cur] == 3)
            {
                answer = max(answer, r - l);
                while (counts[cur] == 3)
                {
                    int t = s[l] - 'a';
                    counts[t]--;
                    l++;
                }
            }
        }
        answer = max(answer, r - l);

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "bcbbbcba";

    int answer = solution.maximumLengthSubstring(s);
    cout << answer << endl;

    return 0;
}
