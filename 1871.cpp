#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        bool answer = false;
        int length = s.length();

        vector<bool> jump(length);
        jump[0] = true;
        for (int i = 0, j = 1; i < length && j < length; i++)
        {
            if (s[i] == '0' && jump[i])
            {
                for (j = max(j, i + minJump); j <= min(i + maxJump, length - 1); j++)
                {
                    jump[j] = (s[j] == '0');
                }
            }
        }

        answer = jump[length - 1];
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "011010";
    int minJump = 2;
    int maxJump = 3;

    bool answer = solution.canReach(s, minJump, maxJump);
    cout << (answer ? "True" : "False") << endl;

    return 0;
}
