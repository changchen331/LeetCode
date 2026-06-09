#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> answer(size, 0);

        vector<int> leftSum(size, 0);
        vector<int> rightSum(size, 0);
        for (int l = 1, r = size - 2; l < size && r > -1; l++, r--)
        {
            leftSum[l] = leftSum[l - 1] + nums[l - 1];
            rightSum[r] = rightSum[r + 1] + nums[r + 1];
        }

        for (int i = 0; i < size; i++)
        {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {10, 4, 8, 3};

    vector<int> answer = solution.leftRightDifference(nums);
    for (auto &&ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
