#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int answer = 0;

        int size_h = hBars.size(), size_v = vBars.size();
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maximum_h = INT_MIN, length_h = 1;
        hBars.emplace_back(-1);
        for (int i = 1; i <= size_h; i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
                length_h++;
            else
            {
                maximum_h = max(maximum_h, length_h);
                length_h = 1;
            }
        }

        int maximum_v = INT_MIN, length_v = 1;
        vBars.emplace_back(-1);
        for (int i = 1; i <= size_v; i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
                length_v++;
            else
            {
                maximum_v = max(maximum_v, length_v);
                length_v = 1;
            }
        }

        int minimum_length = min(maximum_h, maximum_v) + 1;
        answer = minimum_length * minimum_length;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 2;
    int m = 1;
    vector<int> hBars = {2, 3};
    vector<int> vBars = {2};

    int answer = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
    cout << answer << endl;

    return 0;
}
