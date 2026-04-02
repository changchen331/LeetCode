#include <iostream>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int answer = INT_MAX, length = s.length();
        s += s;

        // 解 1（超时）
        // for (int i = 0; i < length; i++)
        // {
        //     int temp = 0;

        //     bool change = false;
        //     for (int j = 1; j < length; j++)
        //     {
        //         int k = i + j;
        //         if (!change && s[k] == s[k - 1])
        //         {
        //             change = true;
        //         }
        //         else if (change && s[k] != s[k - 1])
        //         {
        //             change = true;
        //         }
        //         else
        //         {
        //             change = false;
        //         }

        //         temp += change;
        //     }

        //     answer = min(answer, temp);
        // }

        // 解 2
        int odd_0 = 0, even_0 = 0, odd_1 = 0, even_1 = 0;
        for (int i = 0; i < length; i++)
        {
            if (i % 2 == 1)
            {
                if (s[i] == '0')
                {
                    odd_0++;
                }
                else
                {
                    odd_1++;
                }
            }
            else
            {
                if (s[i] == '0')
                {
                    even_0++;
                }
                else
                {
                    even_1++;
                }
            }
        }
        if (odd_0 + even_1 >= odd_1 + even_0)
        {
            answer = min(answer, odd_1 + even_0);
        }
        else
        {
            answer = min(answer, odd_0 + even_1);
        }

        for (int i = 0, j = length; i < length; i++, j++)
        {
            if (i % 2 == 1)
            {
                if (s[i] == '0')
                {
                    odd_0--;
                }
                else
                {
                    odd_1--;
                }
            }
            else
            {
                if (s[i] == '0')
                {
                    even_0--;
                }
                else
                {
                    even_1--;
                }
            }

            if (j % 2 == 1)
            {
                if (s[j] == '0')
                {
                    odd_0++;
                }
                else
                {
                    odd_1++;
                }
            }
            else
            {
                if (s[j] == '0')
                {
                    even_0++;
                }
                else
                {
                    even_1++;
                }
            }

            if (odd_0 + even_1 >= odd_1 + even_0)
            {
                answer = min(answer, odd_1 + even_0);
            }
            else
            {
                answer = min(answer, odd_0 + even_1);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "111000";

    int answer = solution.minFlips(s);
    cout << answer << endl;

    return 0;
}
