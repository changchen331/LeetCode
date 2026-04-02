#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        if (n == 1)
        {
            return true;
        }

        bool last = n & 1;
        n >>= 1;
        while (n > 0)
        {
            if (!(last ^ (n & 1)))
            {
                return false;
            }
            last = !last;
            n >>= 1;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    bool answer = solution.hasAlternatingBits(n);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
