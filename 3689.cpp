#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int size = nums.size();
        long long answer = 0;

        int maximum = nums[0], minimum = nums[0];
        for (auto &&num : nums)
        {
            maximum = max(maximum, num);
            minimum = min(minimum, num);
        }

        answer = 1LL * k * (maximum - minimum);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 3, 2};
    int k = 3;

    long long answer = solution.maxTotalValue(nums, k);
    cout << answer << endl;

    return 0;
}
