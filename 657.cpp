#include <iostream>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (auto &&move : moves)
        {
            switch (move)
            {
            case 'U':
                x++;
                break;
            case 'D':
                x--;
                break;
            case 'R':
                y++;
                break;
            case 'L':
                y--;
                break;
            default:
                break;
            }
        }

        return x == 0 && y == 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string moves = "UD";

    bool answer = solution.judgeCircle(moves);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
