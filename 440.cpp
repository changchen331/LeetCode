#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        int answer = 1;

        k--;
        while (k > 0)
        {
            long long step = 0;
            long long first = answer, last = answer + 1;
            while (first <= n)
            {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k)
            {
                answer++;
                k -= step;
            }
            else
            {
                answer *= 10;
                k--;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 13;
    int k = 2;

    int answer = solution.findKthNumber(n, k);
    cout << answer << endl;

    return 0;
}
