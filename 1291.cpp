#include <vector>
#include <iostream>
using namespace std;

vector<int> sequential_digits;
int init = []
{
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j <= 10 - i; j++)
        {
            string temp = "";
            for (int k = 0; k < i; k++)
            {
                temp += '0' + j + k;
            }
            sequential_digits.push_back(stoi(temp));
        }
    }
    return 0;
}();

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> answer;
        for (int i = 0; i < sequential_digits.size(); i++)
        {
            int cur = sequential_digits[i];
            if (cur >= low && cur <= high)
            {
                answer.push_back(cur);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int low = 1000;
    int high = 13000;

    vector<int> answer = solution.sequentialDigits(low, high);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
