#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        int answer = 0, length = s.length();
        sort(s.begin(), s.end());

        int odd_max = 0, eve_min = INT_MAX, count = 0;
        char last = s[0];

        for (int i = 0; i < length; i++)
        {
            char c = s[i];

            if (last == c)
                count++;
            else if (last != c)
            {
                if (count % 2 == 1)
                    odd_max = max(odd_max, count);
                else
                    eve_min = min(eve_min, count);
                last = c;
                count = 1;
            }
        }

        if (count % 2 == 1)
            odd_max = max(odd_max, count);
        else
            eve_min = min(eve_min, count);
        answer = odd_max - eve_min;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "muuffffu";

    int answer = solution.maxDifference(s);
    cout << answer << endl;

    return 0;
}
