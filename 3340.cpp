#include <iostream>
using namespace std;

class Solution
{
public:
    bool isBalanced(string num)
    {
        int length = num.length();
        int odd_sum = 0, eve_sum = 0;

        for (int i = 0; i < length; i++)
        {
            int current = num[i] - '0';
            i % 2 == 1 ? odd_sum += current : eve_sum += current;
        }
        return odd_sum == eve_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string num = "24123";

    bool answer = solution.isBalanced(num);
    cout << (answer ? "true" : "false") << endl;

    return 0;
}
