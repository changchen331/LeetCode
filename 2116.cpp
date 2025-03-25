#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int length = s.length();
        if (length % 2)
            return false;

        vector<int> left_positions, unlocked_positions;
        for (int i = 0; i < length; i++)
        {
            if (locked[i] == '0')
            {
                unlocked_positions.push_back(i);
                continue;
            }

            if (s[i] == '(')
                left_positions.push_back(i);
            else
            {
                if (left_positions.empty())
                {
                    if (unlocked_positions.empty())
                        return false;
                    else
                        unlocked_positions.pop_back();
                }
                else
                    left_positions.pop_back();
            }
        }

        while (!left_positions.empty())
        {
            if (unlocked_positions.empty())
                return false;
            if (left_positions.back() > unlocked_positions.back())
                return false;
            else
            {
                left_positions.pop_back();
                unlocked_positions.pop_back();
            }
        }

        return unlocked_positions.size() % 2 == 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "(((())(((())";
    string locked = "111111010111";

    bool answer = solution.canBeValid(s, locked);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
