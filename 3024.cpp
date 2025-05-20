#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        if (nums[0] + nums[1] <= nums[2])
            return "none";

        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";

        if (nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";

        return "scalene";
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 3, 3};

    string answer = solution.triangleType(nums);
    cout << answer << endl;

    return 0;
}
