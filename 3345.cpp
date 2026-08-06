#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> mem(101, 0);
int init = []
{
    for (int i = 1; i < 101; i++)
    {
        long long mul = 1;
        int temp = i;
        while (temp > 0)
        {
            int cur = temp % 10;
            if (cur == 0)
            {
                mul = 0;
                break;
            }
            mul *= cur;
            temp /= 10;
        }
        mem[i] = mul;
    }
    return 0;
}();

class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        int answer = 0;

        for (; n < 101; n++)
        {
            if (mem[n] % t == 0)
            {
                answer = n;
                break;
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 15;
    int t = 3;

    int answer = solution.smallestNumber(n, t);
    cout << answer << endl;

    return 0;
}
