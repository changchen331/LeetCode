#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = 1; i < size; i++)
            answer = max(answer, abs(nums[i] - nums[i - 1]));

        return max(answer, abs(nums[0] - nums.back()));
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 4};

    int answer = solution.maxAdjacentDistance(nums);
    cout << answer << endl;

    return 0;
}
