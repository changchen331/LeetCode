#include <iostream>
using namespace std;

class Solution
{
public:
    int minMaxDifference(int num)
    {
        int answer = 0;

        string num_str = to_string(num);
        int size = num_str.size();

        string maximum = num_str, minimum = num_str;

        for (int i = 0, t = -1; i < size; i++)
        {
            // 最大值
            if (t == -1 && num_str[i] < '9')
                t = i;
            if (t > -1 && num_str[i] == num_str[t])
                maximum[i] = '9';

            // 最小值
            if (num_str[i] == num_str[0])
                minimum[i] = '0';
        }

        return answer = stoi(maximum) - stoi(minimum);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int num = 90;

    int answer = solution.minMaxDifference(num);
    cout << answer << endl;

    return 0;
}
