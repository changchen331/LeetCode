#include <iostream>
using namespace std;

class Solution
{
public:
    string generateString(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();

        int length = m + n - 1;
        string answer(length, 'E');

        // T
        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'F')
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (answer[i + j] == 'E')
                {
                    answer[i + j] = str2[j];
                }
                else if (answer[i + j] != str2[j])
                {
                    return "";
                }
            }
        }

        // F
        string temp = answer;
        for (auto &&ans : answer)
        {
            if (ans == 'E')
            {
                ans = 'a';
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (str1[i] == 'T')
            {
                continue;
            }

            string sub = answer.substr(i, n);
            if (sub == str2)
            {
                bool same = true;
                for (int j = 0; j < n; j++)
                {
                    if (temp[i + n - 1 - j] == 'E')
                    {
                        answer[i + n - 1 - j] = 'b';
                        same = false;
                        break;
                    }
                }
                if (same)
                {
                    return "";
                }
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string str1 = "TFFFTFFF";
    string str2 = "bab";

    string answer = solution.generateString(str1, str2);
    cout << answer << endl;

    return 0;
}
