#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int answer = 0;

        for (int i = low; i <= high; i++)
        {
            string num_str = to_string(i);
            int length = num_str.length();
            if (length % 2)
                continue;

            // 方法 1
            // int left = 0, right = 0;
            // for (int head = 0, tail = length - 1; head < tail; head++, tail--)
            // {
            //     left += num_str[head];
            //     right += num_str[tail];
            // }
            // answer += left == right;

            // 方法 2
            answer += accumulate(num_str.begin(), num_str.begin() + length / 2, 0) == accumulate(num_str.begin() + length / 2, num_str.end(), 0);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int low = 1;
    int high = 100;

    int answer = solution.countSymmetricIntegers(low, high);
    cout << answer << endl;

    return 0;
}
