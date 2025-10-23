#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        int count = s.length();
        while (count > 2)
        {
            for (int i = 0; i < count - 1; i++)
                s[i] = (s[i] + s[i + 1]) % 10;
            count--;
        }

        return s[0] == s[1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "34789";

    bool answer = solution.hasSameDigits(s);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
