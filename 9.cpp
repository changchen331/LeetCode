#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else if (x % 10 == 0)
            return false;

        int temp = 0;
        while (x > temp)
        {
            temp = temp * 10 + (x % 10);
            if (x == temp)
                break;
            x /= 10;
        }

        return x == temp;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int x = 121;

    bool answer = solution.isPalindrome(x);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
