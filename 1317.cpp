#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool check(int n)
    {
        string n_str = to_string(n);
        for (auto &&c : n_str)
            if (c == '0')
                return false;
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            int temp = n - i;
            if (check(i) && check(temp))
                return {i, temp};
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    vector<int> answer = solution.getNoZeroIntegers(n);
    for (auto &&ans : answer)
        cout << ans << (ans != answer.back() ? " " : "\n");

    return 0;
}
