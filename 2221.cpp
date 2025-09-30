#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = size - 1; i > 0; i--)
            for (int j = 0; j < i; j++)
                nums[j] = (nums[j] + nums[j + 1]) % 10;
        answer = nums[0];

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};

    int answer = solution.triangularSum(nums);
    cout << answer << endl;

    return 0;
}
