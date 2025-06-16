#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int answer = 0, size = nums.size();

        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                answer = max(answer, nums[j] - nums[i]);

        return answer ? answer : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums{3, 2, 2, 1};

    int answer = solution.maximumDifference(nums);
    cout << answer << endl;

    return 0;
}
