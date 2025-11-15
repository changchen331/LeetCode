#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int answer = 0, length = s.length();

        vector<int> position0 = {-1};
        int total1 = 0;
        for (int r = 0; r < length; r++)
        {
            if (s[r] == '0')
                position0.emplace_back(r);
            else
            {
                total1++;
                answer += r - position0.back();
            }

            int m = position0.size();
            for (int i = m - 1; i > 0 && (m - i) * (m - i) <= total1; i--)
            {
                int p = position0[i - 1], q = position0[i];
                int count0 = m - i;
                int count1 = r - q + 1 - count0;
                answer += max(q - max(count0 * count0 - count1, 0) - p, 0);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "101101";

    int answer = solution.numberOfSubstrings(s);
    cout << answer << endl;

    return 0;
}
