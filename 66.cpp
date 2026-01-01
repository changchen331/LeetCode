#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = digits.size();

        int position = size - 1;
        for (; position > -1; position--)
        {
            int &digit = digits[position];
            if (digit == 9)
                digit = 0;
            else
            {
                digit++;
                break;
            }
        }

        if (position == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> digits = {9, 9, 9, 9, 9, 9};

    vector<int> answer = solution.plusOne(digits);
    for (auto &&ans : answer)
        cout << ans;
    cout << endl;

    return 0;
}
