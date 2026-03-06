#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        s.push_back('0');
        int length = s.length();

        int count = -1;
        for (int i = 0; i < length; i++)
        {
            if (count > 0)
                return false;

            if (s[i] == '1')
            {
                while (s[i + 1] == '1')
                    i++;
                count++;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "1001";

    bool answer = solution.checkOnesSegment(s);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
