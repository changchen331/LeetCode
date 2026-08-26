#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string answer = "";
        s.push_back('e');
        int len = s.length();

        int left = 0;
        for (; left < len; left++)
        {
            if (s[left] == '1')
            {
                break;
            }
        }
        int righ = left;

        int count = 0;
        for (; righ < len; righ++)
        {
            char cur = s[righ];
            count += (cur == '1');
            if (count == k)
            {
                string sub = s.substr(left, righ - left + 1);
                if (answer.length() == 0)
                {
                    answer = sub;
                }
                else
                {
                    int alen = answer.length();
                    int blen = sub.length();
                    if (alen > blen)
                    {
                        answer = sub;
                    }
                    else if (alen == blen)
                    {
                        answer = min(answer, sub);
                    }
                }

                left++;
                for (; left < righ; left++)
                {
                    if (s[left] == '1')
                    {
                        break;
                    }
                }
                count--;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "01011101000111110";
    int k = 5;

    string answer = solution.shortestBeautifulSubstring(s, k);
    cout << answer << endl;

    return 0;
}
