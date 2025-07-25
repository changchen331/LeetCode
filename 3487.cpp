#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int answer = nums.back(), size = nums.size();

        int last = nums.back();
        for (int i = size - 1; i >= 0; i--)
        {
            if (nums[i] <= 0)
                continue;

            if (last != nums[i])
            {
                answer += nums[i];
                last = nums[i];
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 2, -1, -2, 1, 0, -1};

    int answer = solution.maxSum(nums);
    cout << answer << endl;

    return 0;
}
