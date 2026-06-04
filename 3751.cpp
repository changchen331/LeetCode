#include <vector>
#include <iostream>
using namespace std;

vector<int> waves(100'001, 0);
int init = []
{
    for (int num = 101; num < 100'001; num++)
    {
        string str = to_string(num);
        for (int i = 1; i < str.length() - 1; i++)
        {
            int a = str[i - 1], b = str[i], c = str[i + 1];
            int peak = (a < b) && (b > c);
            int valley = (a > b) && (b < c);
            waves[num] += peak + valley;
        }
    }

    return 0;
}();

class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int answer = 0;

        for (int n = num1; n <= num2; n++)
        {
            if (n <= 100)
            {
                continue;
            }
            answer += waves[n];
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int num1 = 120;
    int num2 = 130;

    int answer = solution.totalWaviness(num1, num2);
    cout << answer << endl;

    return 0;
}
