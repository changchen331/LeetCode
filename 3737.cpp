#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int answer = 0;

        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count += (nums[i] == target);
        }
        if (count == 0)
        {
            return answer;
        }

        int max_length = min(size, 2 * count);
        for (int i = 0; i < size; i++)
        {
            int count_target = 0;
            for (int j = 0; j + i < size && j < max_length; j++)
            {
                count_target += nums[i + j] == target;
                answer += count_target * 2 > j + 1;
            }
        }

        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;

    int answer = solution.countMajoritySubarrays(nums, target);
    cout << answer << endl;

    return 0;
}
