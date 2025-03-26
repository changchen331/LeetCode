#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int length = palindrome.length();
        if (length == 1)
            return "";

        // 我的方法
        // for (int i = 0; i < length; i++)
        // {
        //     if (i == length / 2 && length % 2 == 1)
        //         continue;
        //     if (palindrome[i] != 'a')
        //     {
        //         palindrome[i] = 'a';
        //         break;
        //     }
        //     if (i == length - 1 && palindrome[i] == 'a')
        //         palindrome[i] = 'b';
        // }
        // return palindrome;

        // 官解（更巧妙）
        for (int i = 0; i < length / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[length - 1] = 'b';
        return palindrome;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string palindrome = "abccba";

    string answer = solution.breakPalindrome(palindrome);
    cout << answer << endl;

    return 0;
}
