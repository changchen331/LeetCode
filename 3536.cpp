#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        int answer = 0;
        int a = -1, b = -1;

        while (n > 0)
        {
            int temp = n % 10;

            if (a < temp)
            {
                b = a;
                a = temp;
            }
            else if (b < temp)
            {
                b = temp;
            }

            n /= 10;
        }
        answer = a * b;

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 124;

    int answer = solution.maxProduct(n);
    cout << answer << endl;

    return 0;
}
