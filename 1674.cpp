#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {
        int size = nums.size();
        int answer = INT_MAX;

        vector<int> diff(2 * limit + 2);
        for (int i = 0; i < size / 2; i++)
        {
            int x = nums[i], y = nums[size - 1 - i];
            int left = min(x, y) + 1;
            int right = max(x, y) + limit;

            // 2 ~ left
            diff[2] += 2;
            diff[left] -= 2;

            // left ~ right
            diff[left] += 1;
            diff[right + 1]--;

            // x + y
            diff[x + y] -= 1;
            diff[x + y + 1] += 1;

            // right ~ 2*limit
            diff[right + 1] += 2;
        }

        int sum = 0;
        for (int i = 2; i <= 2 * limit; i++)
        {
            sum += diff[i];
            answer = min(answer, sum);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 4, 3};
    int limit = 4;

    int answer = solution.minMoves(nums, limit);
    cout << answer << endl;

    return 0;
}
