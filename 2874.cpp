#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long answer = 0;
        int size = nums.size();

        int maximum = nums[0], maximum_diff = 0;
        for (int i = 1; i < size; i++)
        {
            answer = max(answer, (1LL * maximum_diff * nums[i]));
            maximum_diff = max(maximum_diff, maximum - nums[i]);
            maximum = max(maximum, nums[i]);
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{1, 10, 3, 4, 19};

    long long answer = solution.maximumTripletValue(nums);
    cout << answer << endl;

    return 0;
}
