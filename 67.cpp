#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string answer = "";

        while (a.length() < b.length())
            a.insert(a.begin(), '0');
        while (a.length() > b.length())
            b.insert(b.begin(), '0');

        int length = max(a.length(), b.length());
        bool flag = false;
        for (int i = length - 1; i > -1; i--)
        {
            int add = a[i] + b[i] - 2 * '0';
            if (add == 2)
            {
                answer.push_back('0' + flag);
                flag = true;
            }
            else if (add == 1)
            {
                if (flag)
                    answer.push_back('1' - (flag = true));
                else
                    answer.push_back('1');
            }
            else
            {
                if (flag)
                    answer.push_back('1' + (flag = false));
                else
                    answer.push_back('0');
            }
        }
        if (flag)
            answer.push_back('1');

        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string a = "1010";
    string b = "1011";

    string answer = solution.addBinary(a, b);
    cout << answer << endl;

    return 0;
}
