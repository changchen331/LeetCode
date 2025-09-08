#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> answer(n, 0);

        for (int i = 0, current = 1; i < n - (n % 2); i += 2, current++)
        {
            answer[i] = current;
            answer[i + 1] = -current;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = 31;

    vector<int> answer = solution.sumZero(n);
    for (auto &&ans : answer)
        cout << ans << (ans != answer.back() ? " " : "\n");

    return 0;
}
