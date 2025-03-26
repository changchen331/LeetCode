#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int answer = 0, size = nums.size();
        vector<int> maximums(size), minimums(size);

        // 方法一
        // int maximum = maximums[0] = nums[0], minimum = minimums[size - 1] = nums[size - 1];
        // for (int i = 1, j = size - 2; i < size; i++, j--)
        // {
        //     maximums[i] = maximum = max(maximum, nums[i]);
        //     minimums[j] = minimum = min(minimum, nums[j]);
        // }

        // for (int i = 1; i < size - 1; i++)
        // {
        //     int num = nums[i];
        //     if (maximums[i - 1] < num && num < minimums[i + 1])
        //         answer += 2;
        //     else if (nums[i - 1] < num && num < nums[i + 1])
        //         answer += 1;
        // }

        // 方法一（改进版）
        minimums[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--)
            minimums[i] = min(minimums[i + 1], nums[i]);

        int maximum = nums[0];
        for (int i = 1; i < size - 1; i++)
        {
            int num = nums[i];
            if (maximum < num && num < minimums[i + 1])
                answer += 2;
            else if (nums[i - 1] < num && num < nums[i + 1])
                answer += 1;
            maximum = max(maximum, num);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, 3};

    int answer = solution.sumOfBeauties(nums);
    cout << answer << endl;

    return 0;
}
