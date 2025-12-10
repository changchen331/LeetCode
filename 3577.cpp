#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int MOD = 1'000'000'007;

public:
    int countPermutations(vector<int> &complexity)
    {
        long long answer = 1;
        int size = complexity.size();

        int top = complexity[0];
        for (int i = 1; i < size; i++)
            if (complexity[i] <= top)
                return 0;

        for (int i = size - 1; i > 0; i--)
        {
            answer *= i;
            answer %= MOD;
        }

        return answer % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> complexity = {3, 3, 3, 4, 4, 4};

    int answer = solution.countPermutations(complexity);
    cout << answer << endl;

    return 0;
}
