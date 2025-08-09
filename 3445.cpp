#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxDifference(string s, int k)
    {
        int inf = INT_MAX / 2;
        int answer = -inf, length = s.length();

        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 5; y++)
            {
                if (y == 5)
                    continue;

                vector<int> current(5), previous(5);
                vector<vector<int>> min_s = {{inf, inf}, {inf, inf}};
                int left = 0;
                for (int i = 0; i < length; i++)
                {
                    current[s[i] - '0']++;
                    int r = i + 1;
                    while (r - left >= k && current[x] > previous[x] && current[y] > previous[y])
                    {
                        int &p = min_s[previous[x] & 1][previous[y] & 1];
                        p = min(p, previous[x] - previous[y]);
                        previous[s[left] - '0']++;
                        left++;
                    }
                    answer = max(answer, current[x] - current[y] - min_s[current[x] & 1 ^ 1][current[y] & 1]);
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "12233";
    int k = 4;

    int answer = solution.maxDifference(s, k);
    cout << answer << endl;

    return 0;
}
