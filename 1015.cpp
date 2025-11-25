#include <iostream>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0)
            return -1;

        for (int i = 0, count = 1, current = 1; i < k; i++, count++, current = current * 10 + 1)
        {
            current %= k;
            if (current == 0)
                return count;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int k = 3;

    int answer = solution.smallestRepunitDivByK(k);
    cout << answer << endl;

    return 0;
}
