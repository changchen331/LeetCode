#include <iostream>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int answer = 0, length = moves.length();

        int l = 0, r = 0, count = 0;
        for (auto &&move : moves)
        {
            if (move == 'L')
            {
                l++;
            }
            else if (move == 'R')
            {
                r++;
            }
            else
            {
                count++;
            }
        }

        if (l >= r)
        {
            answer = l + count - r;
        }
        else
        {
            answer = r + count - l;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string moves = "L_RL__R";

    int answer = solution.furthestDistanceFromOrigin(moves);
    cout << answer << endl;

    return 0;
}
