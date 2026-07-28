#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        string answer;
        int size = s.size();

        // 方法一
        // answer = s;
        // sort(s.begin(), s.end());
        // if (size % 2)
        // {
        //     s.push_back('E');
        // }
        // int len = s.length();
        // for (int i = 0; i < len;)
        // {
        //     char a = s[i];
        //     if (a == 'E')
        //     {
        //         break;
        //     }
        //     char b = s[i + 1];

        //     if (a != b)
        //     {
        //         answer[size / 2] = a;
        //         i += 1;
        //     }
        //     else
        //     {
        //         answer[i / 2] = a;
        //         answer[size - 1 - i / 2] = b;
        //         i += 2;
        //     }
        // }

        // 方法二
        vector<int> cnt(26, 0);
        for (int i = 0; i < size; i++)
        {
            cnt[s[i] - 'a']++;
        }
        char mid = 'E';
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
            {
                continue;
            }
            char cur = 'a' + i;

            if (cnt[i] % 2)
            {
                mid = cur;
                cnt[i]--;
            }
            while (cnt[i] > 0)
            {
                answer.push_back(cur);
                cnt[i] -= 2;
            }
        }
        string head = answer;
        reverse(answer.begin(), answer.end());
        if (mid != 'E')
        {
            head += mid;
        }
        answer = head + answer;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "rur";

    string answer = solution.smallestPalindrome(s);
    cout << answer << endl;

    return 0;
}
