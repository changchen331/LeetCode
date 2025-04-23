#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long answer = 0;
        int size = nums.size();

        // 方法一（超时）
        // for (int i = 0; i < size - 1; i++)
        // {
        //     int &numA = nums[i];
        //     for (int j = i + 1; j < size; j++)
        //     {
        //         int temp = numA + nums[j];
        //         answer += lower <= temp && temp <= upper;
        //     }
        // }

        // 方法二
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            auto right = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            auto left = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            answer += right - left;
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;

    long long answer = solution.countFairPairs(nums, lower, upper);
    cout << answer << endl;

    return 0;
}
