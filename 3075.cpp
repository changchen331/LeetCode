#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long answer = 0;
        int size = happiness.size();
        sort(happiness.begin(), happiness.end(), greater());

        for (int i = 0; i < k; i++)
        {
            int current = happiness[i] - i;
            if (current <= 0)
                break;
            answer += current;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> happiness = {1, 2, 3};
    int k = 2;

    long long answer = solution.maximumHappinessSum(happiness, k);
    cout << answer << endl;

    return 0;
}
