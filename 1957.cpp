#include <iostream>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string answer = "";
        int length = s.length();

        char record = '0';
        int count = 0;

        for (int i = 0; i < length; i++)
        {
            char current = s[i];
            if (record == current)
            {
                if (++count > 1)
                    continue;
            }
            else
            {
                record = current;
                count = 0;
            }

            answer.push_back(current);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "leeetcode";

    string answer = solution.makeFancyString(s);
    cout << answer << endl;

    return 0;
}
