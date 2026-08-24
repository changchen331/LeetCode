#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        bool answer = false;
        int len = num.length() / 2;

        int left = 0, righ = 0;
        int lnon = 0, rnon = 0;
        for (int i = 0; i < len; i++)
        {
            char l = num[i];
            if (l == '?')
            {
                lnon++;
            }
            else
            {
                left += l - '0';
            }

            char r = num[i + len];
            if (r == '?')
            {
                rnon++;
            }
            else
            {
                righ += r - '0';
            }
        }
        int total = lnon + rnon;

        if (total % 2 == 1)
        {
            answer = true;
        }
        else
        {
            if ((left - righ) == (rnon - lnon) / 2 * 9)
            {
                answer = false;
            }
            else
            {
                answer = true;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string num = "25??";

    bool answer = solution.sumGame(num);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
