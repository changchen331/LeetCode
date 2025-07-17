#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int answer = 0;

        vector<vector<int>> f(k, vector<int>(k));
        for (auto &&num : nums)
        {
            num %= k;
            for (int j = 0; j < k; j++)
            {
                f[j][num] = f[num][j] + 1;
                answer = max(answer, f[j][num]);
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5};
    int k = 2;

    int answer = solution.maximumLength(nums, k);
    cout << answer << endl;

    return 0;
}
