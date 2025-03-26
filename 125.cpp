#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int check(char c)
    {
        if (c > 47 && c < 58)
            return 0;
        else if (c > 64 && c < 91)
            return 1;
        else if (c > 96 && c < 123)
            return 2;

        return -1;
    }

public:
    bool isPalindrome(string s)
    {

        // 数字：0-9（ASCII 48-57）
        // 大写字母：A-Z（ASCII 65-90）
        // 小写字母：a-z（ASCII 97-122）
        int size = s.size();

        for (int left = 0, right = size - 1; left <= right;)
        {
            for (; left < right; left++)
            {
                int temp = check(s[left]);
                if (temp == 0 || temp == 1)
                    break;
                else if (temp == 2)
                {
                    s[left] -= 32;
                    break;
                }
            }

            for (; right > left; right--)
            {
                int temp = check(s[right]);
                if (temp == 0 || temp == 1)
                    break;
                else if (temp == 2)
                {
                    s[right] -= 32;
                    break;
                }
            }

            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "A man, a plan, a canal: Panama";

    bool answer = solution.isPalindrome(s);
    cout << (answer ? "true" : "false");

    return 0;
}
