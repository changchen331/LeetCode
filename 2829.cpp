#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        int answer = 0;

        for (int i = 1, j = 0; i <= n; i++)
        {
            if (i <= k / 2)
                answer += i;
            else
                answer += k + j++;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 5;
    int k = 4;

    int answer = solution.minimumSum(n, k);
    cout << answer << endl;

    return 0;
}
